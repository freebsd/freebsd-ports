--- ../bridges/source/jni_uno/jni_uno2java.cxx.orig	Tue Mar 11 12:35:07 2003
+++ ../bridges/source/jni_uno/jni_uno2java.cxx	Tue Mar 11 12:35:29 2003
@@ -62,7 +62,9 @@
 #if defined _MSC_VER
 #include <malloc.h>
 #else
+#if !defined( FREEBSD)
 #include <alloca.h>
+#endif
 #endif
 
 #include "rtl/ustrbuf.hxx"
