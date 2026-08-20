--- flow/Platform.actor.cpp.orig	2026-04-16 19:21:39 UTC
+++ flow/Platform.actor.cpp
@@ -1980,6 +1980,9 @@ std::vector<std::string> getEnvironmentKnobOptions() {
 }
 
 std::vector<std::string> getEnvironmentKnobOptions() {
+#if defined(__FreeBSD__)
+	extern char** environ;
+#endif
 	constexpr const size_t ENVKNOB_PREFIX_LEN = sizeof(ENVIRONMENT_KNOB_OPTION_PREFIX) - 1;
 	std::vector<std::string> knobOptions;
 #if defined(_WIN32)
@@ -1995,7 +1998,7 @@ std::vector<std::string> getEnvironmentKnobOptions() {
 	}
 #else
 	char** e = nullptr;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	e = environ;
 #elif defined(__APPLE__)
 	e = *_NSGetEnviron();
