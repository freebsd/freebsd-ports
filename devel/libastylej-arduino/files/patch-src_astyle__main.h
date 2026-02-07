--- src/astyle_main.h.orig	2016-10-19 22:42:25 UTC
+++ src/astyle_main.h
@@ -422,9 +422,9 @@ void  STDCALL javaErrorHandler(int error
 char* STDCALL javaMemoryAlloc(unsigned long memoryNeeded);
 // the following function names are constructed from method names in the calling java program
 extern "C" EXPORT
-jstring STDCALL Java_AStyleInterface_AStyleGetVersion(JNIEnv* env, jclass);
+jstring STDCALL Java_cc_arduino_packages_formatter_AStyleInterface_AStyleGetVersion(JNIEnv* env, jclass);
 extern "C" EXPORT
-jstring STDCALL Java_AStyleInterface_AStyleMain(JNIEnv* env,
+jstring STDCALL Java_cc_arduino_packages_formatter_AStyleInterface_AStyleMain(JNIEnv* env,
                                                 jobject obj,
                                                 jstring textInJava,
                                                 jstring optionsJava);
