--- flow/Platform.actor.cpp.orig	2023-09-26 04:25:05 UTC
+++ flow/Platform.actor.cpp
@@ -1979,6 +1979,9 @@ std::string epochsToGMTString(double epochs) {
 }
 
 std::vector<std::string> getEnvironmentKnobOptions() {
+#if defined(__FreeBSD__)
+	extern char** environ;
+#endif
 	constexpr const size_t ENVKNOB_PREFIX_LEN = sizeof(ENVIRONMENT_KNOB_OPTION_PREFIX) - 1;
 	std::vector<std::string> knobOptions;
 #if defined(_WIN32)
@@ -1994,7 +1997,7 @@ std::vector<std::string> getEnvironmentKnobOptions() {
 	}
 #else
 	char** e = nullptr;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	e = environ;
 #elif defined(__APPLE__)
 	e = *_NSGetEnviron();
