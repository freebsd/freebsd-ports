/*
 * extract_sysctl.c — FreeBSD/DragonFly sysctl OID collector (pass A).
 *
 * Collects SYSCTL_* macro invocations into CBMSysctl records. The runtime
 * dotted path (kern.ipc.maxsockbuf) is NOT resolved here — it requires the
 * cross-file parent walk done by the repo-level pass (pass_sysctl.c), because a
 * leaf names a parent C-symbol whose defining SYSCTL_NODE often lives in
 * another translation unit.
 *
 * Two parse shapes must both be handled (verified against vendored
 * tree-sitter-c):
 *   - bare   SYSCTL_INT(...)     -> call_expression(identifier, argument_list)
 *   - static SYSCTL_NODE(...)    -> ERROR node; the macro name is an identifier
 *                                   child and the args nest inside a second
 *                                   inner ERROR node.
 * Arguments are therefore read by flattening the terminal tokens between the
 * macro '(' and its matching ')' and splitting on top-level commas — robust to
 * whichever container/nesting the grammar produced.
 *
 * Intra-procedural resolution (recovers the SYSCTL_ADD_* / SYSCTL_CHILDREN
 * dynamic-node family, ~half of all leaves): within a translation unit we
 * track two local-variable aliasings so a leaf whose parent is a local var can
 * still be attributed:
 *     node     = SYSCTL_ADD_NODE(ctx, parent, nbr, "seg", ...);
 *     children = SYSCTL_CHILDREN(node);
 *     SYSCTL_ADD_INT(ctx, children, ..., "leaf", ...);
 * We synthesize a stable symbol "<parent_sym>_<seg>" for such runtime nodes so
 * the resolver joins them into the static tree, yielding the TEMPLATE path
 * (e.g. dev.igb.rx_bytes) — the per-instance index (dev.igb.0.…) only exists at
 * runtime and is intentionally out of scope.
 *
 * See docs/sysctl-extractor-design.md.
 */
#include "cbm.h"
#include "arena.h"
#include "helpers.h"
#include "foundation/constants.h"
#include "extract_node_stack.h"
#include "tree_sitter/api.h"
#include <string.h>
#include <stdio.h>

enum {
    SYSCTL_STACK_CAP = 8192,
    SYSCTL_MAX_ARGS = 16,
    SYSCTL_ALIAS_CAP = 512,   /* local var aliases tracked per file */
    SYSCTL_TOKBUF = 256,      /* max length of one flattened arg */
};

/* ── local-variable alias table (intra-procedural) ─────────────────
 * Maps a C local variable name to the sysctl node C-symbol it refers to.
 * Populated by `x = SYSCTL_ADD_NODE(...)` and `x = SYSCTL_CHILDREN(y)`. */
typedef struct {
    const char *var;    /* borrowed — arena */
    const char *symbol; /* node C-symbol this var aliases (borrowed) */
} sysctl_alias_t;

typedef struct {
    sysctl_alias_t items[SYSCTL_ALIAS_CAP];
    int count;
} sysctl_alias_table_t;

static void alias_put(sysctl_alias_table_t *t, const char *var, const char *symbol) {
    if (!var || !symbol) {
        return;
    }
    for (int i = 0; i < t->count; i++) {
        if (strcmp(t->items[i].var, var) == 0) {
            t->items[i].symbol = symbol; /* last assignment wins */
            return;
        }
    }
    if (t->count < SYSCTL_ALIAS_CAP) {
        t->items[t->count].var = var;
        t->items[t->count].symbol = symbol;
        t->count++;
    }
}

static const char *alias_get(const sysctl_alias_table_t *t, const char *var) {
    if (!var) {
        return NULL;
    }
    for (int i = 0; i < t->count; i++) {
        if (strcmp(t->items[i].var, var) == 0) {
            return t->items[i].symbol;
        }
    }
    return NULL;
}

/* ── macro classification ──────────────────────────────────────────
 * Returns 0 = ignore, 1 = node, 2 = leaf. Sets *is_add for SYSCTL_ADD_* (extra
 * leading ctx arg) and *is_root for root nodes (name in a shifted slot, no
 * parent). */
static int classify_macro(const char *m, bool *is_add, bool *is_root) {
    *is_add = false;
    *is_root = false;
    if (strncmp(m, "SYSCTL_", 7) != 0) {
        return 0;
    }
    const char *tail = m + 7;
    if (strncmp(tail, "ADD_", 4) == 0) {
        *is_add = true;
        tail += 4;
    }
    static const char *ignore[] = {
        "DECL",   "CHILDREN",     "PARENT",  "STATIC_CHILDREN", "FOREACH",
        "IN",     "OUT",          "OUT_STR", "HANDLER_ARGS",    "SIZEOF",
        "SIZEOF_STRUCT", "ENFORCE_FLAGS", "NODE_CHILDREN", NULL,
    };
    for (int i = 0; ignore[i]; i++) {
        if (strcmp(tail, ignore[i]) == 0) {
            return 0;
        }
    }
    if (strncmp(tail, "ROOT_NODE", 9) == 0) {
        *is_root = true;
        return 1;
    }
    if (strncmp(tail, "NODE", 4) == 0) { /* NODE, NODE_WITH_LABEL */
        return 1;
    }
    return 2; /* every remaining SYSCTL_* declares a leaf */
}

/* ── argument flattening ───────────────────────────────────────────
 * Collect the comma-separated argument slots of the invocation rooted at
 * `inv` into `out`. Walks terminal tokens, tracks paren depth, splits on
 * top-level commas. Each slot is arena-allocated, surrounding spaces trimmed.
 * Returns the number of args (>= 0). */
typedef struct {
    CBMExtractCtx *ctx;
    const char **out;
    int max;
    int n;
    char cur[SYSCTL_TOKBUF];
    int cl;
    int depth;
} argflat_t;

static void af_flush(argflat_t *a) {
    if (a->n >= a->max) {
        a->cl = 0;
        return;
    }
    /* trim trailing spaces */
    while (a->cl > 0 && a->cur[a->cl - 1] == ' ') {
        a->cl--;
    }
    a->cur[a->cl] = '\0';
    const char *p = a->cur;
    while (*p == ' ') {
        p++;
    }
    a->out[a->n++] = cbm_arena_strndup(a->ctx->arena, p, strlen(p));
    a->cl = 0;
}

/* Append a node's verbatim source span to the current slot, no added spaces. */
static void af_emit_span(argflat_t *a, TSNode n) {
    uint32_t sb = ts_node_start_byte(n);
    uint32_t eb = ts_node_end_byte(n);
    for (uint32_t i = sb; i < eb && a->cl < SYSCTL_TOKBUF - 1; i++) {
        a->cur[a->cl++] = a->ctx->source[i];
    }
}

static void af_walk(argflat_t *a, TSNode n) {
    const char *t = ts_node_type(n);

    /* Treat string literals and nested calls (e.g. SYSCTL_CHILDREN(x)) as
     * atomic argument tokens — recursing into them would inject spaces between
     * their sub-tokens and corrupt the value. Only at arg depth. */
    if (a->depth >= 1 &&
        (strcmp(t, "string_literal") == 0 || strcmp(t, "call_expression") == 0 ||
         strcmp(t, "concatenated_string") == 0)) {
        af_emit_span(a, n);
        return;
    }

    uint32_t nc = ts_node_child_count(n);
    if (nc == 0) {
        if (strcmp(t, ",") == 0) {
            if (a->depth == 1) {
                af_flush(a);
            } else if (a->cl < SYSCTL_TOKBUF - 1) {
                a->cur[a->cl++] = ',';
            }
            return;
        }
        if (strcmp(t, "(") == 0) {
            a->depth++;
            if (a->depth == 1) {
                return; /* opening paren of the macro call */
            }
        }
        if (strcmp(t, ")") == 0) {
            a->depth--;
            if (a->depth == 0) {
                return; /* closing paren of the macro call */
            }
        }
        if (a->depth >= 1) {
            af_emit_span(a, n); /* verbatim, no space padding */
        }
        return;
    }
    for (uint32_t i = 0; i < nc; i++) {
        af_walk(a, ts_node_child(n, i));
    }
}

static int collect_args(CBMExtractCtx *ctx, TSNode inv, const char **out, int max) {
    argflat_t a = {.ctx = ctx, .out = out, .max = max, .n = 0, .cl = 0, .depth = 0};
    af_walk(&a, inv);
    af_flush(&a); /* final slot */
    return a.n;
}

/* ── string / identifier helpers ───────────────────────────────────── */

/* Strip surrounding double quotes from a string-literal arg; return the inner
 * text (arena). Returns NULL if not a quoted literal. */
static const char *unquote(CBMExtractCtx *ctx, const char *s) {
    if (!s) {
        return NULL;
    }
    size_t len = strlen(s);
    if (len >= 2 && s[0] == '"' && s[len - 1] == '"') {
        return cbm_arena_strndup(ctx->arena, s + 1, len - 2);
    }
    return NULL;
}

/* Extract the inner symbol of a SYSCTL_CHILDREN(x) / SYSCTL_STATIC_CHILDREN(x)
 * argument. Returns the "x" token (arena), or NULL if the arg is not such a
 * wrapper. */
static const char *children_inner(CBMExtractCtx *ctx, const char *arg) {
    if (!arg) {
        return NULL;
    }
    const char *open = NULL;
    if (strncmp(arg, "SYSCTL_CHILDREN(", 16) == 0) {
        open = arg + 16;
    } else if (strncmp(arg, "SYSCTL_STATIC_CHILDREN(", 23) == 0) {
        open = arg + 23;
    } else {
        return NULL;
    }
    const char *close = strchr(open, ')');
    size_t n = close ? (size_t)(close - open) : strlen(open);
    /* trim spaces */
    while (n > 0 && open[0] == ' ') {
        open++;
        n--;
    }
    while (n > 0 && open[n - 1] == ' ') {
        n--;
    }
    return cbm_arena_strndup(ctx->arena, open, n);
}

/* Synthesize a stable node symbol "<parent>_<seg>" for a runtime-added node so
 * the resolver can join it into the static tree as a template path. */
static const char *synth_symbol(CBMExtractCtx *ctx, const char *parent_sym, const char *seg) {
    if (!parent_sym || !seg) {
        return NULL;
    }
    size_t n = strlen(parent_sym) + 1 + strlen(seg) + 1;
    char *buf = cbm_arena_alloc(ctx->arena, n);
    snprintf(buf, n, "%s_%s", parent_sym, seg);
    return buf;
}

/* Resolve an argument that should name a parent OID-list to a node C-symbol:
 *   - "SYSCTL_CHILDREN(v)"  -> alias_get(v)  (or "_<v>" static node symbol)
 *   - a known local alias    -> its symbol
 *   - a bare "_foo" static    -> itself
 * Returns NULL if not resolvable. */
/* Derive the driver name for a device-tree sysctl from the source path, e.g.
 * sys/dev/bnxt/bnxt_en/bnxt_sysctl.c -> "bnxt". Returns a synthetic pre-resolved
 * root symbol "@dev.<driver>" (the resolver treats a leading '@' as a literal
 * path prefix), or NULL if the path is not under sys/dev/. These sysctls live in
 * the runtime dev.<driver>.<unit>.* namespace; we recover the driver-level
 * TEMPLATE path (unit index is runtime-only and intentionally omitted). */
static const char *device_tree_root(CBMExtractCtx *ctx) {
    const char *p = ctx->rel_path;
    if (!p) {
        return NULL;
    }
    const char *dev = strstr(p, "sys/dev/");
    if (!dev) {
        dev = (strncmp(p, "dev/", 4) == 0) ? p : NULL;
        if (!dev) {
            return NULL;
        }
        dev += 4;
    } else {
        dev += 8; /* strlen("sys/dev/") */
    }
    const char *slash = strchr(dev, '/');
    size_t n = slash ? (size_t)(slash - dev) : strlen(dev);
    if (n == 0 || n > 48) {
        return NULL;
    }
    char *sym = cbm_arena_alloc(ctx->arena, 5 + n + 1); /* "@dev." + name */
    snprintf(sym, 5 + n + 1, "@dev.%.*s", (int)n, dev);
    return sym;
}

static const char *resolve_parent_arg(CBMExtractCtx *ctx, const sysctl_alias_table_t *aliases,
                                      const char *arg) {
    if (!arg) {
        return NULL;
    }
    /* Device drivers register under SYSCTL_CHILDREN(device_get_sysctl_tree(dev)),
     * a runtime node. Recover the dev.<driver> template from the file path. */
    if (strstr(arg, "device_get_sysctl_tree") != NULL) {
        return device_tree_root(ctx);
    }
    const char *inner = children_inner(ctx, arg);
    if (inner) {
        const char *sym = alias_get(aliases, inner);
        if (sym) {
            return sym;
        }
        if (strstr(inner, "device_get_sysctl_tree") != NULL) {
            return device_tree_root(ctx);
        }
        /* SYSCTL_CHILDREN(&static_node) or SYSCTL_CHILDREN(static_sym) */
        if (inner[0] == '&') {
            inner++;
        }
        return inner; /* static node C-symbol */
    }
    const char *sym = alias_get(aliases, arg);
    if (sym) {
        return sym;
    }
    if (arg[0] == '_') {
        return arg; /* bare static node symbol like _kern_ipc */
    }
    return NULL; /* unresolved local (e.g. a function param) */
}

/* Best-effort handler identifier: for PROC/OID the function pointer arg. Scan
 * from the tail for the first token that is a plain identifier (not a string,
 * address-of, number, or NULL). */
static const char *guess_handler(const char **args, int argc, int base) {
    for (int i = argc - 1; i >= base; i--) {
        const char *a = args[i];
        if (a && a[0] != '"' && a[0] != '&' && a[0] != '0' && a[0] != '(' &&
            strcmp(a, "NULL") != 0 && (a[0] == '_' || (a[0] >= 'a' && a[0] <= 'z') ||
                                       (a[0] >= 'A' && a[0] <= 'Z'))) {
            return a;
        }
    }
    return NULL;
}

/* ── record emission ───────────────────────────────────────────────── */

/* Process one SYSCTL_* invocation. `assign_target` is the LHS var name when the
 * invocation is the RHS of an assignment/declarator (for alias tracking), else
 * NULL. */
/* When alias_only is true, update the alias table but do NOT push a record —
 * used during the pass-1 alias-collection sweeps to avoid duplicate records. */
static void process_invocation_ex(CBMExtractCtx *ctx, sysctl_alias_table_t *aliases,
                                  const char *macro, TSNode site, const char *assign_target,
                                  bool alias_only) {
    bool is_add = false, is_root = false;
    int kind = classify_macro(macro, &is_add, &is_root);
    if (kind == 0) {
        return;
    }

    const char *args[SYSCTL_MAX_ARGS];
    int argc = collect_args(ctx, site, args, SYSCTL_MAX_ARGS);
    int base = is_add ? 1 : 0; /* skip leading ctx for SYSCTL_ADD_* */

    const char *parent_arg = NULL;
    const char *seg = NULL; /* leaf/segment name */

    if (is_root) {
        /* ROOT_NODE(nbr, name, ...) / ADD_ROOT_NODE(ctx, nbr, name, ...) */
        if (argc > base + 1) {
            seg = args[base + 1];
        }
    } else {
        if (argc > base + 0) {
            parent_arg = args[base + 0];
        }
        if (argc > base + 2) {
            seg = args[base + 2];
        }
    }
    if (!seg) {
        return;
    }
    /* seg may be a quoted string (runtime ADD_) or a bare token (static). */
    const char *seg_str = unquote(ctx, seg);
    if (seg_str) {
        seg = seg_str;
    }

    /* Resolve parent to a node C-symbol (static or via local alias). */
    const char *parent_sym =
        is_root ? NULL : resolve_parent_arg(ctx, aliases, parent_arg);

    const char *self_sym = NULL;
    if (kind == 1) {
        /* A node: its own symbol is <parent>_<seg> (static) or synthesized. */
        if (is_root) {
            size_t n = 1 + strlen(seg) + 1;
            char *buf = cbm_arena_alloc(ctx->arena, n);
            snprintf(buf, n, "_%s", seg);
            self_sym = buf;
        } else if (parent_sym) {
            self_sym = synth_symbol(ctx, parent_sym, seg);
        }
        /* Track alias: `x = SYSCTL_ADD_NODE(...)` binds x to this node. */
        if (assign_target && self_sym) {
            alias_put(aliases, assign_target, self_sym);
        }
    }

    if (alias_only) {
        return; /* pass-1 sweep: alias recorded above, emit nothing */
    }

    CBMSysctl s = {
        .leaf_name = seg,
        .parent_symbol = parent_sym,
        .self_symbol = self_sym,
        .handler = guess_handler(args, argc, base),
        .enclosing_func_qn = cbm_enclosing_func_qn_cached(ctx, site),
        .file_rel = ctx->rel_path,
        .is_node = (kind == 1),
        .line = (int)ts_node_start_point(site).row + 1,
    };
    cbm_sysctl_push(&ctx->result->sysctls, ctx->arena, s);
}

static void process_invocation(CBMExtractCtx *ctx, sysctl_alias_table_t *aliases,
                               const char *macro, TSNode site, const char *assign_target) {
    process_invocation_ex(ctx, aliases, macro, site, assign_target, false);
}

/* Handle `lhs = SYSCTL_CHILDREN(x)` / `lhs = SYSCTL_STATIC_CHILDREN(x)`:
 * bind lhs to the same node x aliases (no record emitted — CHILDREN is an
 * accessor, not a declaration). Returns true if consumed. */
static bool try_children_assign(CBMExtractCtx *ctx, sysctl_alias_table_t *aliases,
                                const char *lhs, const char *rhs_text) {
    const char *inner = children_inner(ctx, rhs_text);
    if (!inner || !lhs) {
        return false;
    }
    const char *sym = alias_get(aliases, inner);
    if (!sym) {
        if (inner[0] == '&') {
            inner++;
        }
        sym = inner; /* static node symbol */
    }
    alias_put(aliases, lhs, sym);
    return true;
}

/* ── AST walk ───────────────────────────────────────────────────────
 * Single stack walk. For each node:
 *   - call_expression whose function is a SYSCTL_ identifier -> invocation
 *   - ERROR node whose first identifier child is SYSCTL_     -> invocation
 *   - init_declarator / assignment_expression -> capture LHS var for aliasing
 * The assignment context is detected by inspecting the invocation's parent. */

/* Return the LHS variable name if `call` sits on the RHS of an assignment or
 * an initialized declarator, else NULL. Also handles `lhs = SYSCTL_CHILDREN(x)`
 * for alias-only binding (handled by caller via rhs text). */
static const char *assign_lhs_of(CBMExtractCtx *ctx, TSNode call) {
    TSNode parent = ts_node_parent(call);
    if (ts_node_is_null(parent)) {
        return NULL;
    }
    const char *pt = ts_node_type(parent);
    if (strcmp(pt, "init_declarator") == 0) {
        TSNode decl = ts_node_child_by_field_name(parent, TS_FIELD("declarator"));
        if (!ts_node_is_null(decl)) {
            return cbm_node_text(ctx->arena, decl, ctx->source);
        }
    } else if (strcmp(pt, "assignment_expression") == 0) {
        TSNode lhs = ts_node_child_by_field_name(parent, TS_FIELD("left"));
        if (!ts_node_is_null(lhs)) {
            return cbm_node_text(ctx->arena, lhs, ctx->source);
        }
    }
    return NULL;
}

/* Pass 1: collect local-variable aliases regardless of source order. Kernel
 * registration code frequently uses a node variable (SYSCTL_CHILDREN(x)) many
 * lines BEFORE the `x = SYSCTL_ADD_NODE(...)` that defines it (helper split
 * across functions), so a single source-order pass would resolve the uses
 * before the def. We therefore seed every alias first, then emit. */
static void collect_aliases(CBMExtractCtx *ctx, sysctl_alias_table_t *aliases, TSNode root) {
    TSNodeStack stack;
    ts_nstack_init(&stack, ctx->arena, SYSCTL_STACK_CAP);
    ts_nstack_push(&stack, ctx->arena, root);
    while (stack.count > 0) {
        TSNode node = ts_nstack_pop(&stack);
        if (strcmp(ts_node_type(node), "call_expression") == 0) {
            TSNode fn = ts_node_child_by_field_name(node, TS_FIELD("function"));
            if (!ts_node_is_null(fn) && strcmp(ts_node_type(fn), "identifier") == 0) {
                char *name = cbm_node_text(ctx->arena, fn, ctx->source);
                if (name) {
                    const char *lhs = assign_lhs_of(ctx, node);
                    if (lhs && (strncmp(name, "SYSCTL_CHILDREN", 15) == 0 ||
                                strncmp(name, "SYSCTL_STATIC_CHILDREN", 22) == 0)) {
                        char *rhs = cbm_node_text(ctx->arena, node, ctx->source);
                        try_children_assign(ctx, aliases, lhs, rhs);
                    } else if (lhs && strncmp(name, "SYSCTL_ADD_NODE", 15) == 0) {
                        /* Synthesize the node symbol from its resolved parent so
                         * the var binds to it. alias_only: do not emit a record
                         * here (the main pass emits it). Two sweeps chain
                         * forward references. */
                        process_invocation_ex(ctx, aliases, name, node, lhs, true);
                    }
                }
            }
        }
        ts_nstack_push_children(&stack, ctx->arena, node);
    }
}

static void extract_sysctl_c(CBMExtractCtx *ctx) {
    sysctl_alias_table_t aliases = {.count = 0};

    /* Two alias-collection sweeps: the second resolves forward-referenced node
     * chains that the first could not (a var defined after its use, whose own
     * parent was also a not-yet-seen var). Two passes suffice for the depths
     * seen in practice (root -> group -> leaf); deeper chains degrade to
     * unresolved rather than loop. */
    collect_aliases(ctx, &aliases, ctx->root);
    collect_aliases(ctx, &aliases, ctx->root);

    TSNodeStack stack;
    ts_nstack_init(&stack, ctx->arena, SYSCTL_STACK_CAP);
    ts_nstack_push(&stack, ctx->arena, ctx->root);

    while (stack.count > 0) {
        TSNode node = ts_nstack_pop(&stack);
        const char *nt = ts_node_type(node);

        if (strcmp(nt, "call_expression") == 0) {
            TSNode fn = ts_node_child_by_field_name(node, TS_FIELD("function"));
            if (!ts_node_is_null(fn) &&
                strcmp(ts_node_type(fn), "identifier") == 0) {
                char *name = cbm_node_text(ctx->arena, fn, ctx->source);
                if (name && strncmp(name, "SYSCTL_", 7) == 0) {
                    /* SYSCTL_CHILDREN assignments are alias-only (seeded in
                     * pass 1) — skip here. Everything else emits a record. */
                    if (strncmp(name, "SYSCTL_CHILDREN", 15) != 0 &&
                        strncmp(name, "SYSCTL_STATIC_CHILDREN", 22) != 0) {
                        process_invocation(ctx, &aliases, name, node, NULL);
                    }
                }
            }
        } else if (strcmp(nt, "ERROR") == 0 || strcmp(nt, "macro_type_specifier") == 0) {
            /* `static SYSCTL_NODE(...)` parses two ways depending on context:
             *   - as a bare ERROR node (isolated), or
             *   - as a `macro_type_specifier` inside a `declaration` (in situ,
             *     when the grammar treats the macro as a type). The SYSCTL_
             *     identifier is a direct child either way; args nest below. */
            uint32_t nc = ts_node_child_count(node);
            for (uint32_t i = 0; i < nc; i++) {
                TSNode c = ts_node_child(node, i);
                if (strcmp(ts_node_type(c), "identifier") != 0) {
                    continue;
                }
                char *name = cbm_node_text(ctx->arena, c, ctx->source);
                if (!name || strncmp(name, "SYSCTL_", 7) != 0) {
                    continue;
                }
                /* Such a declaration is never an assignment RHS -> no alias. */
                process_invocation(ctx, &aliases, name, node, NULL);
                break; /* one macro per node */
            }
        }
        ts_nstack_push_children(&stack, ctx->arena, node);
    }
}

void cbm_extract_sysctl(CBMExtractCtx *ctx) {
    /* C only; C++ kernel modules are vanishingly rare and share the grammar. */
    if (ctx->language == CBM_LANG_C || ctx->language == CBM_LANG_CPP) {
        extract_sysctl_c(ctx);
    }
}
