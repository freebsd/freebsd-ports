$FreeBSD$

--- ../ext/plugin/oji-plugin/src/motif/jvm_natives/native.c	22 Jan 2002 19:56:49 -0000	1.5
+++ ../ext/plugin/oji-plugin/src/motif/jvm_natives/native.c	13 Apr 2002 05:11:05 -0000
@@ -590,7 +590,7 @@
     jclass clz = (*env)->FindClass(env, "sun/plugin/navig/motif/Worker");
     jmethodID meth = (*env)->GetStaticMethodID(env, clz, "readHttpsURL",
 			"(Ljava/lang/Object;[BII)I");
-    return (jint)(*env)->CallStaticObjectMethod(env, clz, meth, this, buf, offset, len);
+    return (jint)(*env)->CallStaticIntMethod(env, clz, meth, this, buf, offset, len);
 }
 
 /*
@@ -605,7 +605,7 @@
     jclass clz = (*env)->FindClass(env, "sun/plugin/navig/motif/Worker");
     jmethodID meth = (*env)->GetStaticMethodID(env, clz, "bytesAvailable",
 			"(Ljava/lang/Object;)I");
-    return (jint)(*env)->CallStaticObjectMethod(env, clz, meth, this);
+    return (jint)(*env)->CallStaticIntMethod(env, clz, meth, this);
 }
 
 /*
@@ -623,7 +623,7 @@
 			"(Ljava/lang/Object;)V");
     jfieldID nativeConnID = (*env)->GetFieldID(env, isClass, "nativeConnection", "J");
 
-    (*env)->CallStaticObjectMethod(env, clz, meth, is);
+    (*env)->CallStaticVoidMethod(env, clz, meth, is);
 
     /* 
        It is extremely important to unset the nativeConnection field in 
