--- src/frontends/audacious/plugin.c~
+++ src/frontends/audacious/plugin.c
@@ -75,6 +75,10 @@ static void uade_seek(int time);
 
 /* GLOBAL VARIABLE DECLARATIONS */
 
+static gchar *fmts[] = {
+	"ahx", NULL
+};
+
 static InputPlugin uade_ip = {
   .description = "UADE " UADE_VERSION,
   .init = uade_init,
@@ -87,6 +90,9 @@ static InputPlugin uade_ip = {
   .cleanup = uade_cleanup,
   .get_song_info = uade_get_song_info,
   .file_info_box = uade_file_info,
+#ifdef __AUDACIOUS_INPUT_PLUGIN_API__
+  .vfs_extensions = fmts,
+#endif
 };
 
 #ifndef __AUDACIOUS_INPUT_PLUGIN_API__
