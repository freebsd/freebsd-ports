--- src/crashprint.cpp.orig	2016-06-25 12:26:20 UTC
+++ src/crashprint.cpp
@@ -31,11 +31,9 @@
 #endif
 
 //! standard header
-#if defined(__linux__)
 #include <execinfo.h>    // Needed for backtrace
 #include <cxxabi.h>      // Needed for __cxa_demangle
 #include <unistd.h>
-#endif
 
 // wxWidgets headers
 #include <wx/string.h>   // strings support
