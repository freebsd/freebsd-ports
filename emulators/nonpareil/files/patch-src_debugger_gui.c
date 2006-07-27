--- src.orig/debugger_gui.c	Thu Jul 27 19:48:05 2006
+++ src/debugger_gui.c	Thu Jul 27 19:49:43 2006
@@ -34,6 +34,11 @@
 #include "display.h"
 #include "proc.h"
 
+#ifndef PRIx64
+#define PRIx64 "llx"
+#define PRIu64 "llu"
+#define PRIo64 "llo"
+#endif
 
 static GtkWidget *reg_window;
 static gboolean reg_window_visible;
