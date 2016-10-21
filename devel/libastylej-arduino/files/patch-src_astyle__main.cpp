--- src/astyle_main.cpp.orig	2016-10-19 22:42:21 UTC
+++ src/astyle_main.cpp
@@ -3550,7 +3550,7 @@ using namespace astyle;
 // called by a java program to get the version number
 // the function name is constructed from method names in the calling java program
 extern "C"  EXPORT
-jstring STDCALL Java_AStyleInterface_AStyleGetVersion(JNIEnv* env, jclass)
+jstring STDCALL Java_cc_arduino_packages_formatter_AStyleInterface_AStyleGetVersion(JNIEnv* env, jclass)
 {
 	return env->NewStringUTF(g_version);
 }
@@ -3558,7 +3558,7 @@ jstring STDCALL Java_AStyleInterface_ASt
 // called by a java program to format the source code
 // the function name is constructed from method names in the calling java program
 extern "C"  EXPORT
-jstring STDCALL Java_AStyleInterface_AStyleMain(JNIEnv* env,
+jstring STDCALL Java_cc_arduino_packages_formatter_AStyleInterface_AStyleMain(JNIEnv* env,
                                                 jobject obj,
                                                 jstring textInJava,
                                                 jstring optionsJava)
