--- internal/cbm/cbm.h.orig	2026-08-18 20:39:59 UTC
+++ internal/cbm/cbm.h
@@ -355,6 +355,21 @@ typedef struct {
     CBMChannelDirection direction;
 } CBMChannel;
 
+// FreeBSD/DragonFly sysctl OID declaration collected from a SYSCTL_* macro.
+// The runtime dotted path (kern.ipc.maxsockbuf) is NOT stored here — it is
+// resolved by the repo-level pass_sysctl walk, which joins parent_symbol chains
+// across files. See docs/sysctl-extractor-design.md.
+typedef struct {
+    const char *leaf_name;         // arg segment, e.g. "maxsockbuf" or node "ipc"
+    const char *parent_symbol;     // parent C-symbol, e.g. "_kern_ipc"; NULL for roots
+    const char *self_symbol;       // this node's own C-symbol (nodes only), else NULL
+    const char *handler;           // best-effort handler ident (PROC/OID), else NULL
+    const char *enclosing_func_qn; // QN of the enclosing function, if any
+    const char *file_rel;          // borrowed rel path (for the emitted node)
+    bool is_node;                  // true = defines a subtree node; false = a leaf
+    int line;                      // 1-based source line
+} CBMSysctl;
+
 // Rust: impl Trait for Struct
 typedef struct {
     const char *trait_name;  // trait name (raw text)
@@ -468,6 +483,12 @@ typedef struct {
     int cap;
 } CBMChannelArray;
 
+typedef struct {
+    CBMSysctl *items;
+    int count;
+    int cap;
+} CBMSysctlArray;
+
 // Full extraction result for one file.
 typedef struct CBMFileResult {
     CBMArena arena; // owns local memory; composites may also retain child arenas below
@@ -486,6 +507,7 @@ typedef struct CBMFileResult {
     CBMStringRefArray string_refs;       // URL/config string literals from AST
     CBMInfraBindingArray infra_bindings; // topic→URL pairs from IaC configs
     CBMChannelArray channels;            // Socket.IO / EventEmitter pub/sub participation
+    CBMSysctlArray sysctls;              // FreeBSD/DragonFly SYSCTL_* OID declarations
 
     const char *module_qn;      // module qualified name
     const char *namespace_name; // declared namespace/package (Java/Kotlin/C#/PHP), NULL if none
@@ -722,6 +744,7 @@ void cbm_channels_push(CBMChannelArray *arr, CBMArena 
 void cbm_impltrait_push(CBMImplTraitArray *arr, CBMArena *a, CBMImplTrait it);
 void cbm_resolvedcall_push(CBMResolvedCallArray *arr, CBMArena *a, CBMResolvedCall rc);
 void cbm_channels_push(CBMChannelArray *arr, CBMArena *a, CBMChannel ch);
+void cbm_sysctl_push(CBMSysctlArray *arr, CBMArena *a, CBMSysctl s);
 
 // --- Sub-extractor entry points ---
 
@@ -733,6 +756,7 @@ void cbm_extract_channels(CBMExtractCtx *ctx);
 void cbm_extract_env_accesses(CBMExtractCtx *ctx);
 void cbm_extract_type_assigns(CBMExtractCtx *ctx);
 void cbm_extract_channels(CBMExtractCtx *ctx);
+void cbm_extract_sysctl(CBMExtractCtx *ctx);
 
 // Single-pass unified extraction (replaces the 7 calls above except defs+imports).
 void cbm_extract_unified(CBMExtractCtx *ctx);
