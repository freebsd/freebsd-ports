--- lang/LangPrimSource/PyrPrimitive.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangPrimSource/PyrPrimitive.cpp
@@ -4248,7 +4248,7 @@ void initMIDIPrimitives();
 	initMIDIPrimitives();
 #endif
 
-#if !defined(_WIN32) && !defined(SC_IPHONE) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(SC_IPHONE) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 void initLIDPrimitives();
 	initLIDPrimitives();
 #endif
