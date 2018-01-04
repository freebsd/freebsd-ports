--- src/cpp/core/Backtrace.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/core/Backtrace.cpp
@@ -46,7 +46,7 @@ std::string demangle(const std::string& 
 
 void printBacktrace(std::ostream& os)
 {
-#ifndef _WIN32
+#if !defined(_WIN32) && !defined(__FreeBSD__)
    
    os << "Backtrace (most recent calls first):" << std::endl << std::endl;
    
