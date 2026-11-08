/*
 * pass_sysctl.c — FreeBSD/DragonFly sysctl OID-tree resolution (pass B).
 *
 * Two stages:
 *   1. cbm_sysctl_emit_raw_for_file() — called per file from the definitions /
 *      parallel consume step. Emits one provisional "SysctlDecl" node per
 *      collected CBMSysctl record, carrying the raw parent/self C-symbols in
 *      its properties. Runs in both the sequential and parallel pipelines
 *      (the per-file CBMFileResult is available there; result_cache is freed
 *      before predump).
 *   2. cbm_pipeline_resolve_sysctl() — a graph-only predump pass. Reads back
 *      all SysctlDecl nodes, builds a symbol -> (segment, parent_symbol) table
 *      from the node-kind decls, resolves each leaf's parent chain to a dotted
 *      runtime path (kern.ipc.maxsockbuf), and emits a deduplicated "Sysctl"
 *      node per resolved path plus an IMPLEMENTS_SYSCTL edge from the handler /
 *      enclosing function. Being graph-only, it is path-independent.
 *
 * See docs/sysctl-extractor-design.md.
 */
#include "pipeline/pipeline.h"
#include "pipeline/pipeline_internal.h"
#include "graph_buffer/graph_buffer.h"
#include "foundation/log.h"
#include "foundation/constants.h"
#include "cbm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    SR_MAX_DEPTH = 24,      /* max OID tree depth for the parent walk */
    SR_SYM = 160,           /* max C-symbol length */
    SR_SEG = 96,            /* max segment length */
    SR_PATH = 640,          /* max dotted path length */
};

/* Fixed root OID symbols -> their segment, in case a root's SYSCTL_ROOT_NODE
 * decl is in a file that was not indexed (headers, arch-specific). */
static const struct {
    const char *sym;
    const char *seg;
} SR_ROOTS[] = {
    {"_kern", "kern"},         {"_vm", "vm"},         {"_vfs", "vfs"},
    {"_net", "net"},           {"_debug", "debug"},   {"_hw", "hw"},
    {"_machdep", "machdep"},   {"_user", "user"},     {"_p1003_1b", "p1003_1b"},
    {"_security", "security"}, {"_dev", "dev"},       {"_compat", "compat"},
    {"_regression", "regression"}, {"_sysctl", "sysctl"}, {NULL, NULL},
};

/* ── stage 1: provisional per-file emission ─────────────────────────── */

void cbm_sysctl_emit_raw_for_file(cbm_pipeline_ctx_t *ctx, const CBMFileResult *result,
                                  const char *rel) {
    if (!ctx || !result) {
        return;
    }
    for (int j = 0; j < result->sysctls.count; j++) {
        const CBMSysctl *s = &result->sysctls.items[j];
        if (!s->leaf_name || !s->leaf_name[0]) {
            continue;
        }
        const char *file = s->file_rel ? s->file_rel : (rel ? rel : "");
        /* Stable, unique-per-site qn so upsert does not collapse distinct
         * declarations that happen to share a leaf name. */
        char qn[CBM_SZ_512];
        snprintf(qn, sizeof(qn), "__sysctldecl__%s:%d:%s", file, s->line, s->leaf_name);

        /* All fields are C identifiers — no JSON escaping required. */
        char props[CBM_SZ_1K];
        snprintf(props, sizeof(props),
                 "{\"leaf\":\"%s\",\"parent_symbol\":\"%s\",\"self_symbol\":\"%s\","
                 "\"handler\":\"%s\",\"enclosing\":\"%s\",\"is_node\":%s}",
                 s->leaf_name, s->parent_symbol ? s->parent_symbol : "",
                 s->self_symbol ? s->self_symbol : "", s->handler ? s->handler : "",
                 s->enclosing_func_qn ? s->enclosing_func_qn : "",
                 s->is_node ? "true" : "false");

        cbm_gbuf_upsert_node(ctx->gbuf, "SysctlDecl", s->leaf_name, qn, file, s->line,
                             s->line, props);
    }
}

/* ── tiny JSON-field readers (props are flat, identifier-valued) ─────── */

/* Copy the string value of "key" from a flat JSON object into out. Returns
 * true if found and non-empty. */
static bool jget(const char *json, const char *key, char *out, size_t outsz) {
    char pat[64];
    snprintf(pat, sizeof(pat), "\"%s\":\"", key);
    const char *p = strstr(json, pat);
    if (!p) {
        return false;
    }
    p += strlen(pat);
    const char *end = strchr(p, '"');
    if (!end) {
        return false;
    }
    size_t n = (size_t)(end - p);
    if (n == 0 || n >= outsz) {
        if (n >= outsz) {
            n = outsz - 1;
        } else {
            return false;
        }
    }
    memcpy(out, p, n);
    out[n] = '\0';
    return true;
}

static bool jget_bool(const char *json, const char *key) {
    char pat[64];
    snprintf(pat, sizeof(pat), "\"%s\":", key);
    const char *p = strstr(json, pat);
    if (!p) {
        return false;
    }
    p += strlen(pat);
    return strncmp(p, "true", 4) == 0;
}

/* ── node symbol table for parent-chain resolution ──────────────────── */

typedef struct {
    char sym[SR_SYM];
    char seg[SR_SEG];
    char parent[SR_SYM];
    bool has_parent;
} sr_node_t;

typedef struct {
    sr_node_t *items;
    int count;
    int cap;
} sr_table_t;

static sr_node_t *sr_find(sr_table_t *t, const char *sym) {
    for (int i = 0; i < t->count; i++) {
        if (strcmp(t->items[i].sym, sym) == 0) {
            return &t->items[i];
        }
    }
    return NULL;
}

static void sr_add(sr_table_t *t, const char *sym, const char *seg, const char *parent) {
    if (!sym || !sym[0] || sr_find(t, sym)) {
        return;
    }
    if (t->count >= t->cap) {
        int nc = t->cap ? t->cap * 2 : 1024;
        sr_node_t *ni = realloc(t->items, (size_t)nc * sizeof(sr_node_t));
        if (!ni) {
            return;
        }
        t->items = ni;
        t->cap = nc;
    }
    sr_node_t *n = &t->items[t->count++];
    snprintf(n->sym, sizeof(n->sym), "%s", sym);
    snprintf(n->seg, sizeof(n->seg), "%s", seg ? seg : "");
    if (parent && parent[0]) {
        snprintf(n->parent, sizeof(n->parent), "%s", parent);
        n->has_parent = true;
    } else {
        n->parent[0] = '\0';
        n->has_parent = false;
    }
}

/* Walk parent links from `parent_sym` up to a root, joining segments with '.'.
 * Writes the ancestor path (without the leaf) into out. Returns true on a full
 * resolve to a known root, false if a link is missing. */
static bool sr_resolve(sr_table_t *t, const char *parent_sym, char *out, size_t outsz) {
    const char *segs[SR_MAX_DEPTH];
    int sd = 0;
    const char *cur = parent_sym;
    for (int guard = 0; guard < SR_MAX_DEPTH && cur && cur[0]; guard++) {
        /* A symbol beginning with '@' is a synthetic pre-resolved literal path
         * prefix (e.g. "@dev.bnxt" from a device_get_sysctl_tree() parent):
         * emit it verbatim as the top segment and stop the walk. */
        if (cur[0] == '@') {
            if (sd < SR_MAX_DEPTH) {
                segs[sd++] = cur + 1; /* skip '@' */
            }
            break;
        }
        sr_node_t *n = sr_find(t, cur);
        if (!n) {
            return false; /* missing intermediate node */
        }
        if (sd < SR_MAX_DEPTH) {
            segs[sd++] = n->seg;
        }
        if (!n->has_parent) {
            break; /* reached a root */
        }
        cur = n->parent;
    }
    if (sd == 0) {
        return false;
    }
    out[0] = '\0';
    size_t used = 0;
    for (int i = sd - 1; i >= 0; i--) {
        int w = snprintf(out + used, outsz - used, "%s%s", segs[i], i > 0 ? "." : "");
        if (w < 0 || (size_t)w >= outsz - used) {
            return false;
        }
        used += (size_t)w;
    }
    return true;
}

/* ── stage 2: graph-only resolve + emit ─────────────────────────────── */

void cbm_pipeline_resolve_sysctl(cbm_gbuf_t *gb) {
    if (!gb) {
        return;
    }
    const cbm_gbuf_node_t **decls = NULL;
    int decl_count = 0;
    if (cbm_gbuf_find_by_label(gb, "SysctlDecl", &decls, &decl_count) != 0 || decl_count == 0) {
        cbm_log_info("sysctl.skip", "reason", "no_sysctl_decls");
        return;
    }

    sr_table_t table = {0};
    /* Seed fixed roots first so a missing SYSCTL_ROOT_NODE decl still resolves. */
    for (int i = 0; SR_ROOTS[i].sym; i++) {
        sr_add(&table, SR_ROOTS[i].sym, SR_ROOTS[i].seg, NULL);
    }

    /* Pass 2a: register every node-kind decl into the symbol table. */
    for (int i = 0; i < decl_count; i++) {
        const char *props = decls[i]->properties_json;
        if (!props || !jget_bool(props, "is_node")) {
            continue;
        }
        char self[SR_SYM], seg[SR_SEG], parent[SR_SYM];
        if (!jget(props, "self_symbol", self, sizeof(self))) {
            continue;
        }
        if (!jget(props, "leaf", seg, sizeof(seg))) {
            continue;
        }
        bool has_parent = jget(props, "parent_symbol", parent, sizeof(parent));
        sr_add(&table, self, seg, has_parent ? parent : NULL);
    }

    /* Pass 2b: resolve each leaf-kind decl and emit the final Sysctl node. */
    int resolved = 0, unresolved = 0;
    for (int i = 0; i < decl_count; i++) {
        const char *props = decls[i]->properties_json;
        if (!props || jget_bool(props, "is_node")) {
            continue; /* skip node-kind decls; only leaves are user-facing */
        }
        char leaf[SR_SEG], parent[SR_SYM];
        if (!jget(props, "leaf", leaf, sizeof(leaf))) {
            continue;
        }
        bool have_parent = jget(props, "parent_symbol", parent, sizeof(parent));

        char base[SR_PATH];
        char path[SR_PATH];
        bool ok = have_parent && sr_resolve(&table, parent, base, sizeof(base));
        if (ok) {
            snprintf(path, sizeof(path), "%s.%s", base, leaf);
            resolved++;
        } else {
            /* Emit with an unresolved-parent marker so the leaf is still
             * discoverable; never silently drop. */
            snprintf(path, sizeof(path), "<unresolved>.%s", leaf);
            unresolved++;
        }

        char qn[SR_PATH + 16];
        snprintf(qn, sizeof(qn), "__sysctl__%s", path);
        char sprops[CBM_SZ_256];
        snprintf(sprops, sizeof(sprops), "{\"path\":\"%s\",\"resolved\":%s}", path,
                 ok ? "true" : "false");
        int64_t sid = cbm_gbuf_upsert_node(gb, "Sysctl", path, qn, decls[i]->file_path,
                                           decls[i]->start_line, decls[i]->end_line, sprops);

        /* Edge from the implementing function to the sysctl. Prefer the
         * enclosing function QN; fall back to the named handler symbol. */
        if (sid > 0) {
            const cbm_gbuf_node_t *src = NULL;
            char enc[CBM_SZ_512];
            if (jget(props, "enclosing", enc, sizeof(enc)) && enc[0]) {
                src = cbm_gbuf_find_by_qn(gb, enc);
            }
            if (!src) {
                char h[SR_SYM];
                if (jget(props, "handler", h, sizeof(h)) && h[0]) {
                    const cbm_gbuf_node_t **hits = NULL;
                    int hc = 0;
                    if (cbm_gbuf_find_by_name(gb, h, &hits, &hc) == 0 && hc > 0) {
                        src = hits[0];
                    }
                }
            }
            if (src) {
                cbm_gbuf_insert_edge(gb, src->id, sid, "IMPLEMENTS_SYSCTL", "{}");
            }
        }
    }

    free(table.items);
    char rbuf[CBM_SZ_16], ubuf[CBM_SZ_16];
    snprintf(rbuf, sizeof(rbuf), "%d", resolved);
    snprintf(ubuf, sizeof(ubuf), "%d", unresolved);
    cbm_log_info("sysctl.resolved", "resolved", rbuf, "unresolved", ubuf);
}
