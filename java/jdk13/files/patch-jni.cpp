$FreeBSD$
--- ../../hotspot1.3.1/src/share/vm/prims/jni.cpp	17 Aug 2001 22:56:37 -0000	1.1.1.2
+++ ../../hotspot1.3.1/src/share/vm/prims/jni.cpp	27 Jul 2003 10:42:46 -0000	1.2
@@ -743,7 +743,7 @@
   JNI_ArgumentPusherVaArg ap(methodID, args); \
   jni_invoke(env, &jvalue, obj, JNI_VIRTUAL, methodID, &ap, CHECK_0); \
   va_end(args); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END \
 \
 \
@@ -753,7 +753,7 @@
   JavaValue jvalue(Tag); \
   JNI_ArgumentPusherVaArg ap(methodID, args); \
   jni_invoke(env, &jvalue, obj, JNI_VIRTUAL, methodID, &ap, CHECK_0); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END \
 \
 \
@@ -763,7 +763,7 @@
   JavaValue jvalue(Tag); \
   JNI_ArgumentPusherArray ap(methodID, args); \
   jni_invoke(env, &jvalue, obj, JNI_VIRTUAL, methodID, &ap, CHECK_0); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END
 
 // the runtime type of subword integral basic types is integer
@@ -818,7 +818,7 @@
   JNI_ArgumentPusherVaArg ap(methodID, args); \
   jni_invoke(env, &jvalue, obj, JNI_NONVIRTUAL, methodID, &ap, CHECK_0); \
   va_end(args); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END \
 \
 \
@@ -828,7 +828,7 @@
   JavaValue jvalue(Tag); \
   JNI_ArgumentPusherVaArg ap(methodID, args); \
   jni_invoke(env, &jvalue, obj, JNI_NONVIRTUAL, methodID, &ap, CHECK_0); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END \
 \
 \
@@ -838,7 +838,7 @@
   JavaValue jvalue(Tag); \
   JNI_ArgumentPusherArray ap(methodID, args); \
   jni_invoke(env, &jvalue, obj, JNI_NONVIRTUAL, methodID, &ap, CHECK_0); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END
 
 // the runtime type of subword integral basic types is integer
@@ -893,7 +893,7 @@
   JNI_ArgumentPusherVaArg ap(methodID, args); \
   jni_invoke(env, &jvalue, NULL, JNI_STATIC, methodID, &ap, CHECK_0); \
   va_end(args); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END \
 \
 \
@@ -903,7 +903,7 @@
   JavaValue jvalue(Tag); \
   JNI_ArgumentPusherVaArg ap(methodID, args); \
   jni_invoke(env, &jvalue, NULL, JNI_STATIC, methodID, &ap, CHECK_0); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END \
 \
 \
@@ -913,7 +913,7 @@
   JavaValue jvalue(Tag); \
   JNI_ArgumentPusherArray ap(methodID, args); \
   jni_invoke(env, &jvalue, NULL, JNI_STATIC, methodID, &ap, CHECK_0); \
-  return (ResultType)(jvalue._value.##unionType); \
+  return (ResultType)(jvalue._value.unionType); \
 JNI_END
 
 // the runtime type of subword integral basic types is integer
