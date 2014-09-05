--- Zend/zend.h.orig	2014-08-27 13:31:35.000000000 +0000
+++ Zend/zend.h	2014-09-04 07:33:27.289480865 +0000
@@ -193,7 +193,7 @@
 #endif
 #define restrict __restrict__
 
-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN) && !(defined(ZTS) && defined(__FreeBSD__))
 # define ZEND_ALLOCA_MAX_SIZE (32 * 1024)
 # define ALLOCA_FLAG(name) \
 	zend_bool name;
