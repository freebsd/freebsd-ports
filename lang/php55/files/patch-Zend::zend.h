--- Zend/zend.h.orig	2008-08-15 21:47:23.000000000 +0200
+++ Zend/zend.h	2008-09-25 22:52:50.000000000 +0200
@@ -192,7 +192,7 @@
 # define ZEND_FASTCALL
 #endif
 
-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN) && !(defined(ZTS) && defined(__FreeBSD__))
 # define ZEND_ALLOCA_MAX_SIZE (32 * 1024)
 # define ALLOCA_FLAG(name) \
 	zend_bool name;
