--- third_party/angle/src/common/system_utils.cpp.orig	2024-02-21 00:22:07 UTC
+++ third_party/angle/src/common/system_utils.cpp
@@ -25,7 +25,7 @@ std::string GetExecutableName()
 {
 std::string GetExecutableName()
 {
-#if defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21
+#if (defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21) || defined(ANGLE_PLATFORM_BSD)
     // Support for "getprogname" function in bionic was introduced in L (API level 21)
     const char *executableName = getprogname();
     return (executableName) ? std::string(executableName) : "ANGLE";
