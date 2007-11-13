
$FreeBSD$

--- src/plugin_xmms/plugin.c.orig
+++ src/plugin_xmms/plugin.c
@@ -259,6 +259,12 @@
 
 	/* stream */
 
+	/* XXX allow indiscriminate use of g_free() */
+	flac_cfg.stream.proxy_host = g_strdup("");
+	flac_cfg.stream.proxy_user = g_strdup("");
+	flac_cfg.stream.proxy_pass = g_strdup("");
+	flac_cfg.stream.save_http_path = g_strdup("");
+
 	xmms_cfg_read_int(cfg, "flac", "stream.http_buffer_size", &flac_cfg.stream.http_buffer_size);
 	xmms_cfg_read_int(cfg, "flac", "stream.http_prebuffer", &flac_cfg.stream.http_prebuffer);
 	xmms_cfg_read_boolean(cfg, "flac", "stream.use_proxy", &flac_cfg.stream.use_proxy);
@@ -425,8 +431,13 @@
 		if(title) {
 			if (source_to_decoder_type (filename) == DECODER_FILE) {
 				static const char *errtitle = "Invalid FLAC File: ";
-				*title = g_malloc(strlen(errtitle) + 1 + strlen(filename) + 1 + 1);
-				sprintf(*title, "%s\"%s\"", errtitle, filename);
+				if(strlen(errtitle) + 1 + strlen(filename) + 1 + 1 < strlen(filename)) { /* overflow check */
+					*title = NULL;
+				}
+				else {
+					*title = g_malloc(strlen(errtitle) + 1 + strlen(filename) + 1 + 1);
+					sprintf(*title, "%s\"%s\"", errtitle, filename);
+				}
 			} else {
 				*title = NULL;
 			}
