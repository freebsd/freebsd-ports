--- src/slic3r/GUI/HintNotification.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/HintNotification.cpp
@@ -151,7 +151,7 @@ namespace {
 #endif // WIN32
 
 			if (tag == "Linux")
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 				return TagCheckAffirmative;
 #else 
 				return TagCheckNegative;
