--- main/ui-gtk.c.orig	Sun May  4 09:09:51 2003
+++ main/ui-gtk.c	Sun Nov 23 04:32:57 2003
@@ -739,7 +739,7 @@
 /* logging is done this way because this was the best I could come up with
    whilst battling with macros that can only take fixed numbers of arguments */
 
-#define LOG_FUNC(name,level,txt) void ui_log_ ## name ## (const char *text, ...) \
+#define LOG_FUNC(name,level,txt) void ui_log_ ## name (const char *text, ...) \
 { \
   va_list ap; \
   if (gen_loglevel >= level) { \
