Clang 3.4.1 on FreeBSD 10.1/i386 with -std=c++11 does not define i386

--- simgear/nasal/naref.h.orig	2015-03-09 07:33:09.127727983 +0100
+++ simgear/nasal/naref.h	2015-03-09 07:34:06.947658185 +0100
@@ -10,7 +10,7 @@
 /* Win64 and Irix should work with this too, but have not been
  * tested */
 # define NASAL_NAN64
-#elif defined(_M_IX86) || defined(i386) || defined(__x86_64) || \
+#elif defined(_M_IX86) || defined(__i386) || defined(__x86_64) || \
       defined(__ia64__) || defined(_M_IA64) || defined(__ARMEL__) || \
       defined(_M_X64) || defined(__alpha__) || \
       (defined(__sh__) && defined(__LITTLE_ENDIAN__))
