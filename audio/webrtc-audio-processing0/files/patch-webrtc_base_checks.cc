- Drop unnecessary dependency on libexecinfo for GCC build
  https://chromium.googlesource.com/external/webrtc/+/7c4dedade158%5E!/

--- webrtc/base/checks.cc.orig	2018-07-23 14:02:57 UTC
+++ webrtc/base/checks.cc
@@ -11,16 +11,10 @@
 // Most of this was borrowed (with minor modifications) from V8's and Chromium's
 // src/base/logging.cc.
 
-// Use the C++ version to provide __GLIBCXX__.
 #include <cstdarg>
 #include <cstdio>
 #include <cstdlib>
 
-#if defined(__GLIBCXX__) && !defined(__UCLIBC__)
-#include <cxxabi.h>
-#include <execinfo.h>
-#endif
-
 #if defined(WEBRTC_ANDROID)
 #define LOG_TAG "rtc"
 #include <android/log.h>  // NOLINT
@@ -51,39 +45,6 @@ void PrintError(const char* format, ...) {
   va_end(args);
 }
 
-// TODO(ajm): This works on Mac (although the parsing fails) but I don't seem
-// to get usable symbols on Linux. This is copied from V8. Chromium has a more
-// advanced stace trace system; also more difficult to copy.
-void DumpBacktrace() {
-#if defined(__GLIBCXX__) && !defined(__UCLIBC__)
-  void* trace[100];
-  int size = backtrace(trace, sizeof(trace) / sizeof(*trace));
-  char** symbols = backtrace_symbols(trace, size);
-  PrintError("\n==== C stack trace ===============================\n\n");
-  if (size == 0) {
-    PrintError("(empty)\n");
-  } else if (symbols == NULL) {
-    PrintError("(no symbols)\n");
-  } else {
-    for (int i = 1; i < size; ++i) {
-      char mangled[201];
-      if (sscanf(symbols[i], "%*[^(]%*[(]%200[^)+]", mangled) == 1) {  // NOLINT
-        PrintError("%2d: ", i);
-        int status;
-        size_t length;
-        char* demangled = abi::__cxa_demangle(mangled, NULL, &length, &status);
-        PrintError("%s\n", demangled != NULL ? demangled : mangled);
-        free(demangled);
-      } else {
-        // If parsing failed, at least print the unparsed symbol.
-        PrintError("%s\n", symbols[i]);
-      }
-    }
-  }
-  free(symbols);
-#endif
-}
-
 FatalMessage::FatalMessage(const char* file, int line) {
   Init(file, line);
 }
@@ -99,7 +60,6 @@ NO_RETURN FatalMessage::~FatalMessage() {
   fflush(stderr);
   stream_ << std::endl << "#" << std::endl;
   PrintError(stream_.str().c_str());
-  DumpBacktrace();
   fflush(stderr);
   abort();
 }
