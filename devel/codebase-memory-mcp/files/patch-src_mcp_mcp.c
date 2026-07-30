--- src/mcp/mcp.c.orig	2026-06-12 05:05:55 UTC
+++ src/mcp/mcp.c
@@ -4360,6 +4360,7 @@ static void maybe_auto_index(cbm_mcp_server_t *srv) {
 
 /* ── Background update check ──────────────────────────────────── */
 
+#ifndef CBM_PACKAGE_MANAGED
 #define UPDATE_CHECK_URL "https://api.github.com/repos/DeusData/codebase-memory-mcp/releases/latest"
 
 static void *update_check_thread(void *arg) {
@@ -4423,6 +4424,7 @@ static void start_update_check(cbm_mcp_server_t *srv) 
         srv->update_thread_active = true;
     }
 }
+#endif /* !CBM_PACKAGE_MANAGED */
 
 /* Prepend update notice to a tool result, then clear it (one-shot). */
 static char *inject_update_notice(cbm_mcp_server_t *srv, char *result_json) {
@@ -4493,7 +4495,9 @@ char *cbm_mcp_server_handle(cbm_mcp_server_t *srv, con
 
     if (strcmp(req.method, "initialize") == 0) {
         result_json = cbm_mcp_initialize_response(req.params_raw);
+#ifndef CBM_PACKAGE_MANAGED
         start_update_check(srv);
+#endif
         detect_session(srv);
         maybe_auto_index(srv);
     } else if (strcmp(req.method, "ping") == 0) {
