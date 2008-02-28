--- birnet/birnetcdefs.h.orig	2008-02-26 23:16:19.000000000 +0100
+++ birnet/birnetcdefs.h	2008-02-26 23:16:44.000000000 +0100
@@ -24,6 +24,13 @@
 #include <sys/types.h>			/* uint, ssize */
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
