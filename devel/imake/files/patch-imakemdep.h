--- ./imakemdep.h.orig	2012-03-08 06:47:32.000000000 +0100
+++ ./imakemdep.h	2013-06-12 20:22:52.058999526 +0200
@@ -380,7 +383,7 @@
     defined(__GNUC__) || defined(__GLIBC__)
 #    ifdef __i386__
 	"-D__i386__",
-#     if defined(__GNUC__) && (__GNUC__ >= 3)
+#     if defined(__GNUC__) && (__GNUC__ >= 3) && !defined(__FreeBSD__)
 	"-m32",
 #     endif
 #    endif
