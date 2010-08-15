--- cpp/src/IceUtil/Exception.cpp.orig	2010-02-25 16:55:42.000000000 +0100
+++ cpp/src/IceUtil/Exception.cpp	2010-05-16 14:32:45.000000000 +0200
@@ -14,7 +14,7 @@
 #include <ostream>
 #include <cstdlib>
 
-#if defined(__GNUC__) && !defined(__sun)
+#if defined(__GNUC__) && !defined(__sun) && !defined(__FreeBSD__)
 #  include <execinfo.h>
 #  include <cxxabi.h>
 #endif
@@ -52,7 +52,7 @@
 
 Init init;
 
-#if defined(__GNUC__) && !defined(__sun)
+#if defined(__GNUC__) && !defined(__sun) && !defined(__FreeBSD__)
 string
 getStackTrace()
 {
@@ -183,7 +183,7 @@
 IceUtil::Exception::Exception() :
     _file(0),
     _line(0)
-#if defined(__GNUC__) && !defined(__sun)
+#if defined(__GNUC__) && !defined(__sun) && !defined(__FreeBSD__)
     , _stackTrace(getStackTrace())
 #endif
 {
@@ -192,7 +192,7 @@
 IceUtil::Exception::Exception(const char* file, int line) :
     _file(file),
     _line(line)
-#if defined(__GNUC__) && !defined(__sun)
+#if defined(__GNUC__) && !defined(__sun) && !defined(__FreeBSD__)
     , _stackTrace(getStackTrace())
 #endif
 {
