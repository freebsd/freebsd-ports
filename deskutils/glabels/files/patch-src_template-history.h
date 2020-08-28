--- src/template-history.h.orig	2020-08-28 23:00:22 UTC
+++ src/template-history.h
@@ -28,7 +28,7 @@
 G_BEGIN_DECLS
 
 
-glTemplateHistoryModel *gl_template_history;
+extern glTemplateHistoryModel *gl_template_history;
 
 
 void            gl_template_history_init (void);
