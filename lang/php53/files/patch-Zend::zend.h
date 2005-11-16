--- Zend/zend.h.orig	Thu Aug 25 19:41:08 2005
+++ Zend/zend.h	Wed Nov 16 09:30:03 2005
@@ -178,7 +178,7 @@
 #endif
 
 
-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(__darwin__) && !defined(__APPLE__)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(__darwin__) && !defined(__APPLE__) && !(defined(ZTS) && defined(__FreeBSD__))
 # define do_alloca(p) alloca(p)
 # define free_alloca(p)
 #else
