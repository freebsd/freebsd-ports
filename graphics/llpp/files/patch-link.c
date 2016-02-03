--- link.c.orig	2015-10-13 20:12:27 UTC
+++ link.c
@@ -34,12 +34,6 @@
 #include <caml/memory.h>
 #include <caml/unixsupport.h>
 
-#if __GNUC__ < 5
-/* At least gcc (Gentoo 4.9.3 p1.0, pie-0.6.2) 4.9.3 emits erroneous
-   clobbered diagnostics */
-#pragma GCC diagnostic ignored "-Wclobbered"
-#endif
-
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wunused-parameter"
 #pragma GCC diagnostic ignored "-Wshadow"
@@ -3913,8 +3907,7 @@ CAMLprim value ml_platform (value unit_v
     platid = pilinux;
 #elif defined __CYGWIN__
     platid = picygwin;
-#elif defined __DragonFly__ || defined __FreeBSD__
-    || defined __OpenBSD__ || defined __NetBSD__
+#elif defined __DragonFly__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
     platid = pibsd;
 #elif defined __sun__
     platid = pisun;
