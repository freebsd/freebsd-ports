--- plugins/org.eclipse.core.filesystem/natives/unix/freebsd/include/os_custom.h.orig	2008-08-02 10:40:44.000000000 -0400
+++ plugins/org.eclipse.core.filesystem/natives/unix/freebsd/include/os_custom.h	2008-08-02 10:40:55.000000000 -0400
@@ -11,8 +11,8 @@
 ***********************************************************************/
 
 /* Use this directive when introducing platform-specific code in localfile.c */
-#ifndef LINUX
-#define LINUX
+#ifndef FREEBSD
+#define FREEBSD
 #endif
 
 /* FreeBSD supports reading symbolic links */
