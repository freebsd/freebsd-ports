--- jrd/gds.c.orig	Sat Mar  2 00:15:11 2002
+++ jrd/gds.c	Sun Jul  7 14:27:44 2002
@@ -159,7 +159,7 @@
    engine and this change may imply side effect I haven't known 
    about yet. Tomas Nejedlik (tomas@nejedlik.cz)
 */
-#if (defined(LINUX) && defined(SUPERCLIENT))
+#if ((defined(LINUX) || defined(FREEBSD)) && defined(SUPERCLIENT))
 #define V4_THREADING
 #endif
 
@@ -3510,9 +3510,9 @@
 #else
 	       (MAP_ANON | 
 #endif
-#if (!defined LINUX && !defined DARWIN)
-/* In LINUX, Solaris, and Darwin there is no such thing as MAP_VARIABLE. Hence, it gives 
-   compilation error. The equivalent functionality is default, 
+#if (!defined LINUX && !defined DARWIN && !defined FREEBSD)
+/* In LINUX, Solaris, FreeBSD and Darwin there is no such thing as MAP_VARIABLE.
+   Hence, it gives compilation error. The equivalent functionality is default, 
    if you do not specify MAP_FIXED */
 		MAP_VARIABLE | 
 #endif  /* LINUX */
