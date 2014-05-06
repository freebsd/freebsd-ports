--- boost/predef/os/bsd/free.h.orig	2013-10-15 01:23:53.000000000 -0400
+++ boost/predef/os/bsd/free.h	2014-05-06 17:25:43.000000000 -0400
@@ -26,7 +26,7 @@
 
 #define BOOST_OS_BSD_FREE BOOST_VERSION_NUMBER_NOT_AVAILABLE
 
-#if !BOOST_PREDEF_DETAIL_OS_DETECTED && ( \
+#if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && (  \
     defined(__FreeBSD__) \
     )
 #   ifndef BOOST_OS_BSD_AVAILABLE
