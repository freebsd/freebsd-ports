$FreeBSD$

--- ../../deploy/src/plugin/solaris/nscore/JavaVM5.cpp.orig	Thu Jun 15 18:08:03 2006
+++ ../../deploy/src/plugin/solaris/nscore/JavaVM5.cpp	Thu Jul  6 17:10:37 2006
@@ -1289,7 +1289,11 @@
   //          jre/lib/<arch>/classic/libjvm.so
   // (to permit hotspot later).  So this path is only needed for 1.2
 
+#if defined(_ALLBSD_SOURCE) && defined(__amd64__)
+      sprintf(buff, "LD_LIBRARY_PATH=%s/lib/%s/server:%s/lib/%s",
+#else
       sprintf(buff, "LD_LIBRARY_PATH=%s/lib/%s/client:%s/lib/%s",
+#endif
               jre, LIBARCH,                // libjvm
               jre, LIBARCH);               // libjava, libawt & friends
 
