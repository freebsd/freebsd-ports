
$FreeBSD$

--- lib/loop_wchar.h	2001/05/29 09:13:16	1.1
+++ lib/loop_wchar.h	2001/05/29 09:14:16
@@ -32,7 +32,7 @@
 #define mbsinit(ps) 1
 #endif
 #else
-#ifndef mbstate_t
+#if !defined(mbstate_t) && !defined(__FreeBSD__)
 typedef int mbstate_t;
 #endif
 #endif
