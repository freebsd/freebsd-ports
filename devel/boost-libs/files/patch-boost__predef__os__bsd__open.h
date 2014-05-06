--- boost/predef/os/bsd/open.h.orig	2013-10-15 01:23:53.000000000 -0400
+++ boost/predef/os/bsd/open.h	2014-05-06 18:06:32.000000000 -0400
@@ -55,7 +55,7 @@
 
 #define BOOST_OS_BSD_OPEN BOOST_VERSION_NUMBER_NOT_AVAILABLE
 
-#if !BOOST_PREDEF_DETAIL_OS_DETECTED && ( \
+#if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && (  \
     defined(__OpenBSD__) \
     )
 #   ifndef BOOST_OS_BSD_AVAILABLE
