--- Zend/zend.h.orig	2013-12-10 19:32:43.000000000 +0000
+++ Zend/zend.h	2013-12-13 21:55:53.836235768 +0000
@@ -180,7 +180,7 @@ char *alloca ();
 #endif
 #define restrict __restrict__
 
-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN) && !(defined(ZTS) && defined(__FreeBSD__))
 # define ZEND_ALLOCA_MAX_SIZE (32 * 1024)
 # define ALLOCA_FLAG(name) \
 	zend_bool name;
