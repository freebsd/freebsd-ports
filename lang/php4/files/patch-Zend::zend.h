--- Zend/zend.h.orig	Sat Jul 23 13:58:40 2005
+++ Zend/zend.h	Tue Nov 15 23:25:54 2005
@@ -176,7 +176,7 @@
 #endif
 
 
-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(__darwin__) && !defined(__APPLE__)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(__darwin__) && !defined(__APPLE__) && !(defined(ZTS) && defined(__FreeBSD__))
 # define do_alloca(p) alloca(p)
 # define free_alloca(p)
 #else
