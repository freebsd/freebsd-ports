--- src/slic3r/GUI/HintNotification.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/HintNotification.cpp
@@ -151,7 +151,7 @@
 #endif // WIN32

 			if (tag == "Linux")
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 				return TagCheckAffirmative;
 #else
 				return TagCheckNegative;
