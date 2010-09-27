--- birnet/birnetcdefs.h.orig	2010-09-15 12:21:26.000000000 +0000
+++ birnet/birnetcdefs.h	2010-09-15 12:21:17.000000000 +0000
@@ -24,6 +24,13 @@
 #include <float.h>                      /* {FLT|DBL}_{MIN|MAX|EPSILON} */
 #include <birnet/birnetconfig.h>
 
+/*
+ * Dirty hack... no idea why it's needed
+ */
+#ifndef uint
+# define uint unsigned int
+#endif
+
 BIRNET_EXTERN_C_BEGIN();
 
 /* --- standard macros --- */
