--- base/debug/stack_trace.cc.orig	2023-11-29 21:39:40 UTC
+++ base/debug/stack_trace.cc
@@ -266,7 +266,9 @@ void StackTrace::OutputToStream(std::ostream* os) cons
 }
 
 void StackTrace::OutputToStream(std::ostream* os) const {
+#if !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(os, nullptr);
+#endif
 }
 
 std::string StackTrace::ToString() const {
@@ -274,7 +276,7 @@ std::string StackTrace::ToStringWithPrefix(const char*
 }
 std::string StackTrace::ToStringWithPrefix(const char* prefix_string) const {
   std::stringstream stream;
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(&stream, prefix_string);
 #endif
   return stream.str();
