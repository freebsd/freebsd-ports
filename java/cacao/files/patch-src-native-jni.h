--- src/native/jni.h.orig	2007-04-02 13:23:24.000000000 +0200
+++ src/native/jni.h	2009-01-15 20:32:31.000000000 +0100
@@ -45,10 +45,12 @@
 
 #include CLASSPATH_JNI_H
 
-
 #ifndef _JNI_H
 #define _JNI_H
 
+#define JNINativeInterface JNINativeInterface_
+#define JNIInvokeInterface JNIInvokeInterface_
+
 /* forward typedefs ***********************************************************/
 
 typedef struct localref_table localref_table;
