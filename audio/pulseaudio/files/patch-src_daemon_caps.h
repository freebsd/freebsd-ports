--- src/daemon/caps.h.orig	2008-03-31 07:34:39.290608458 -0400
+++ src/daemon/caps.h	2008-03-31 07:36:12.728192195 -0400
@@ -25,7 +25,8 @@
 ***/
 
 void pa_drop_root(void);
-void pa_drop_caps(void);
+/* Defined in caps.c */
+/* void pa_drop_caps(void); */
 int pa_limit_caps(void);
 
 #endif
