--- internal/cbm/cbm.c.orig	2026-10-16 05:39:05 UTC
+++ internal/cbm/cbm.c
@@ -472,6 +472,11 @@ void cbm_diagram_arrows_push(CBMDiagramArrowArray *arr
     arr->items[arr->count++] = da;
 }
 
+void cbm_sysctl_push(CBMSysctlArray *arr, CBMArena *a, CBMSysctl s) {
+    GROW_ARRAY(arr, a);
+    arr->items[arr->count++] = s;
+}
+
 // --- String input reader (for parse_with_options) ---
 
 typedef struct {
@@ -3870,6 +3875,9 @@ static CBMFileResult *extract_file_ex_body(const char 
 
     // Channel detection (Socket.IO / EventEmitter) — JS/TS only.
     cbm_extract_channels(&ctx);
+
+    // FreeBSD/DragonFly sysctl OID collection — C only (no-op elsewhere).
+    cbm_extract_sysctl(&ctx);
 
     // Diagrams: blocks of documents and diagram files (self-gated by language).
     cbm_extract_diagrams(&ctx);
