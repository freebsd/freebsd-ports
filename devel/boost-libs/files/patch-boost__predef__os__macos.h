--- boost/predef/os/macos.h.orig	2013-10-15 01:23:53.000000000 -0400
+++ boost/predef/os/macos.h	2014-05-06 18:06:32.000000000 -0400
@@ -31,7 +31,7 @@
 
 #define BOOST_OS_MACOS BOOST_VERSION_NUMBER_NOT_AVAILABLE
 
-#if !BOOST_PREDEF_DETAIL_OS_DETECTED && ( \
+#if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && (  \
     defined(macintosh) || defined(Macintosh) || \
     (defined(__APPLE__) && defined(__MACH__)) \
     )
