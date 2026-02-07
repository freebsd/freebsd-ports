--- src/font-history.h.orig	2020-08-28 23:00:51 UTC
+++ src/font-history.h
@@ -28,7 +28,7 @@
 G_BEGIN_DECLS
 
 
-glFontHistoryModel *gl_font_history;
+extern glFontHistoryModel *gl_font_history;
 
 
 void            gl_font_history_init (void);
