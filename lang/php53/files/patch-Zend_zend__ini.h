--- Zend/zend_ini.h.orig	2014-12-17 16:24:10 UTC
+++ Zend/zend_ini.h
@@ -28,7 +28,7 @@
 #define ZEND_INI_ALL (ZEND_INI_USER|ZEND_INI_PERDIR|ZEND_INI_SYSTEM)
 
 #ifndef XtOffsetOf
-# if defined(CRAY) || (defined(__arm) && !defined(LINUX))
+# if defined(CRAY) || (defined(__ARMCC_VERSION) && !defined(LINUX))
 # ifdef __STDC__
 # define XtOffset(p_type, field) _Offsetof(p_type, field)
 # else
