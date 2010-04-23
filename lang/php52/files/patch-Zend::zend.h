--- Zend/zend.h.orig	Tue Nov 15 14:35:22 2005
+++ Zend/zend.h	Fri Nov 25 09:31:48 2005
@@ -178,7 +178,7 @@
 #endif
 
 
-#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN)
+#if (HAVE_ALLOCA || (defined (__GNUC__) && __GNUC__ >= 2)) && !(defined(ZTS) && defined(ZEND_WIN32)) && !(defined(ZTS) && defined(NETWARE)) && !(defined(ZTS) && defined(HPUX)) && !defined(DARWIN) && !(defined(ZTS) && defined(__FreeBSD__))
 # define do_alloca(p) alloca(p)
 # define free_alloca(p)
 #else
