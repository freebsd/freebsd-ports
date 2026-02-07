--- src/slic3r/GUI/HintNotification.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/HintNotification.cpp
@@ -161,6 +161,13 @@ TagCheckResult tag_check_system(const std::string& tag
 			return TagCheckNegative;
 #endif // __linux__
 
+		if (tag == "FreeBSD")
+#ifdef __FreeBSD__
+			return TagCheckAffirmative;
+#else 
+			return TagCheckNegative;
+#endif // __FreeBSD__
+
 		if (tag == "OSX")
 #ifdef __APPLE__
 			return TagCheckAffirmative;
