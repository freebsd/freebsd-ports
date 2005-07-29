--- tools/inc/inetdef.hxx.orig	Sun Jul 21 00:59:36 2002
+++ tools/inc/inetdef.hxx	Sun Jul 21 00:59:38 2002
@@ -90,6 +90,8 @@
 #define TOOLS_INETDEF_OS "NETBSD Sparc"
 #elif defined LINUX && defined X86
 #define TOOLS_INETDEF_OS "Linux"
+#elif defined FREEBSD && defined X86
+#define TOOLS_INETDEF_OS "FreeBSD"
 #elif defined SINIX
 #define TOOLS_INETDEF_OS "SINIX"
 #elif defined IRIX
