--- base/debug/stack_trace.cc.orig	2023-03-30 00:33:38 UTC
+++ base/debug/stack_trace.cc
@@ -273,7 +273,9 @@ void StackTrace::Print() const {
 }
 
 void StackTrace::OutputToStream(std::ostream* os) const {
+#if !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(os, nullptr);
+#endif
 }
 
 std::string StackTrace::ToString() const {
@@ -281,7 +283,7 @@ std::string StackTrace::ToString() const {
 }
 std::string StackTrace::ToStringWithPrefix(const char* prefix_string) const {
   std::stringstream stream;
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(&stream, prefix_string);
 #endif
   return stream.str();
