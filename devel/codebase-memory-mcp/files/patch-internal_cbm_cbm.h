--- internal/cbm/cbm.h.orig	2026-10-16 05:39:05 UTC
+++ internal/cbm/cbm.h
@@ -580,6 +580,21 @@ typedef struct {
     const char *type_text;  // raw annotation text, resolved later per file
 } CBMFieldType;
 
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
@@ -826,6 +841,12 @@ typedef struct {
     bool failed;
 } CBMDocLinkArray;
 
+typedef struct {
+    CBMSysctl *items;
+    int count;
+    int cap;
+} CBMSysctlArray;
+
 // Full extraction result for one file.
 typedef struct CBMFileResult {
     CBMArena arena; // owns local memory; composites may also retain child arenas below
@@ -846,6 +867,7 @@ typedef struct CBMFileResult {
     CBMInfraBindingArray infra_bindings; // topic→URL pairs from IaC configs
     CBMK8sFactArray k8s_facts;           // Kubernetes references and CRD declarations
     CBMChannelArray channels;            // Socket.IO / EventEmitter pub/sub participation
+    CBMSysctlArray sysctls;              // FreeBSD/DragonFly SYSCTL_* OID declarations
     CBMDiagramArrowArray diagram_arrows; // arrows between the file's DiagramElement defs
     CBMFieldTypeArray field_types;       // Python: annotated instance fields (#1277)
 
@@ -1326,6 +1348,7 @@ void cbm_channels_push(CBMChannelArray *arr, CBMArena 
 #endif
 void cbm_resolvedcall_push(CBMResolvedCallArray *arr, CBMArena *a, CBMResolvedCall rc);
 void cbm_channels_push(CBMChannelArray *arr, CBMArena *a, CBMChannel ch);
+void cbm_sysctl_push(CBMSysctlArray *arr, CBMArena *a, CBMSysctl s);
 void cbm_diagram_arrows_push(CBMDiagramArrowArray *arr, CBMArena *a, CBMDiagramArrow da);
 
 // --- Sub-extractor entry points ---
@@ -1345,6 +1368,7 @@ void cbm_extract_channels(CBMExtractCtx *ctx);
 void cbm_extract_env_accesses(CBMExtractCtx *ctx);
 void cbm_extract_type_assigns(CBMExtractCtx *ctx);
 void cbm_extract_channels(CBMExtractCtx *ctx);
+void cbm_extract_sysctl(CBMExtractCtx *ctx);
 /* Diagrams (diagram.c): a Diagram definition per diagram -- a Markdown, reST
  * or AsciiDoc block, or a diagram file -- with a DiagramElement definition per
  * element and the arrows between them. */
