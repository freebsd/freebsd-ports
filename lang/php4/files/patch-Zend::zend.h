--- Zend/zend.h.orig    Mon Dec  6 15:42:56 2004
+++ Zend/zend.h Mon Dec  6 15:46:40 2004
@@ -176,7 +176,7 @@
 #endif


-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(__darwin__) && !defined(__APPLE__)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(__darwin__) && !defined(__APPLE__) && !(defined(ZTS) && defined(__FreeBSD__))
 # define do_alloca(p) alloca(p)
 # define free_alloca(p)
 #else

