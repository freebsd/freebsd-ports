--- internal/cbm/cbm.c.orig	2026-08-18 20:39:59 UTC
+++ internal/cbm/cbm.c
@@ -188,6 +188,11 @@ void cbm_channels_push(CBMChannelArray *arr, CBMArena 
     arr->items[arr->count++] = ch;
 }
 
+void cbm_sysctl_push(CBMSysctlArray *arr, CBMArena *a, CBMSysctl s) {
+    GROW_ARRAY(arr, a);
+    arr->items[arr->count++] = s;
+}
+
 // --- String input reader (for parse_with_options) ---
 
 typedef struct {
@@ -1297,6 +1302,9 @@ CBMFileResult *cbm_extract_file_ex(const char *source,
 
     // Channel detection (Socket.IO / EventEmitter) — JS/TS only.
     cbm_extract_channels(&ctx);
+
+    // FreeBSD/DragonFly sysctl OID collection — C only (no-op elsewhere).
+    cbm_extract_sysctl(&ctx);
 
     // K8s / Kustomize semantic pass (additional structured extraction for YAML-based infra files).
     if (ctx.language == CBM_LANG_KUSTOMIZE || ctx.language == CBM_LANG_K8S) {
