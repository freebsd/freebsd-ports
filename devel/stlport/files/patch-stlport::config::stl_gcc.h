--- stlport/config/stl_gcc.h.orig	Thu Jan 10 19:41:58 2002
+++ stlport/config/stl_gcc.h	Thu Jun  6 23:15:40 2002
@@ -250,8 +250,13 @@
 
 # if (__GNUC__ >= 3)
 
+#ifdef __FreeBSD__
+#  define _STLP_NATIVE_INCLUDE_PATH ../g++
+#  define _STLP_NATIVE_OLD_STREAMS_INCLUDE_PATH ../g++/backward
+#else
 #  define _STLP_NATIVE_INCLUDE_PATH ../g++-v3
 #  define _STLP_NATIVE_OLD_STREAMS_INCLUDE_PATH ../g++-v3/backward
+#endif
 
 # elif (__GNUC_MINOR__ < 8)
 
