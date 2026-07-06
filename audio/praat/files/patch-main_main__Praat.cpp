--- main/main_Praat.cpp.orig	2026-06-13 14:46:14 UTC
+++ main/main_Praat.cpp
@@ -70,6 +70,8 @@ static void logo (Graphics graphics) {
 			isArm64 ? U"ARM64 Linux" :
 			x64_version == 3 ? U"x64(v3) Linux" :
 			U"x64(v1) Linux";
+#elif defined(__FreeBSD__)
+U"FreeBSD";
 		#else
 			U"";
 			#error Unknown OS type.
