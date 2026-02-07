--- src/runtime/oclgrind.cpp.orig       2017-01-22 12:14:21 UTC
+++ src/runtime/oclgrind.cpp
@@ -364,6 +364,10 @@ static string getLibDirPath()
 #if defined(__APPLE__)
   uint32_t sz = PATH_MAX;
   if (_NSGetExecutablePath(exepath, &sz))
+#elif defined(__FreeBSD__)
+  char temp[PATH_MAX];
+  snprintf(temp, sizeof(temp), "/proc/%d/file", getpid());
+  if (readlink(temp, exepath, PATH_MAX) == -1)
 #else // not apple
   if (readlink("/proc/self/exe", exepath, PATH_MAX) == -1)
 #endif
