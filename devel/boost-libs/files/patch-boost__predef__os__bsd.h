--- boost/predef/os/bsd.h.orig	2013-10-15 01:23:53.000000000 -0400
+++ boost/predef/os/bsd.h	2014-05-06 18:06:32.000000000 -0400
@@ -59,7 +59,7 @@
 #define BOOST_OS_BSD BOOST_VERSION_NUMBER_NOT_AVAILABLE
 #endif
 
-#if !BOOST_PREDEF_DETAIL_OS_DETECTED && ( \
+#if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && (  \
     defined(BSD) || \
     defined(_SYSTYPE_BSD) \
     )
