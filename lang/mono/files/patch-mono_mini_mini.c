--- ./mono/mini/mini.c.orig	2008-10-20 13:53:02.000000000 -0300
+++ ./mono/mini/mini.c	2008-12-09 15:04:17.000000000 -0300
@@ -78,6 +78,11 @@
 
 #include "debug-mini.h"
 
+// https://bugzilla.novell.com/show_bug.cgi?id=448131
+#if defined(__FreeBSD__)
+#undef MONO_ARCH_SIGSEGV_ON_ALTSTACK
+#endif
+
 #define BRANCH_COST 100
 #define INLINE_LENGTH_LIMIT 20
 #define INLINE_FAILURE do {\
