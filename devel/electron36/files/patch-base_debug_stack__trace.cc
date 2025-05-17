--- base/debug/stack_trace.cc.orig	2025-04-22 20:15:27 UTC
+++ base/debug/stack_trace.cc
@@ -268,7 +268,7 @@ bool StackTrace::WillSymbolizeToStreamForTesting() {
   // Symbols are not expected to be reliable when gn args specifies
   // symbol_level=0.
   return false;
-#elif defined(__UCLIBC__) || defined(_AIX)
+#elif defined(__UCLIBC__) || defined(_AIX) || BUILDFLAG(IS_BSD)
   // StackTrace::OutputToStream() is not implemented under uclibc, nor AIX.
   // See https://crbug.com/706728
   return false;
@@ -321,7 +321,9 @@ void StackTrace::OutputToStreamWithPrefix(std::ostream
     }
     return;
   }
+#if !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefixImpl(os, prefix_string);
+#endif
 }
 
 std::string StackTrace::ToString() const {
@@ -330,7 +332,7 @@ std::string StackTrace::ToStringWithPrefix(cstring_vie
 
 std::string StackTrace::ToStringWithPrefix(cstring_view prefix_string) const {
   std::stringstream stream;
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   OutputToStreamWithPrefix(&stream, prefix_string);
 #endif
   return stream.str();
@@ -354,7 +356,7 @@ std::ostream& operator<<(std::ostream& os, const Stack
 }
 
 std::ostream& operator<<(std::ostream& os, const StackTrace& s) {
-#if !defined(__UCLIBC__) && !defined(_AIX)
+#if !defined(__UCLIBC__) && !defined(_AIX) && !BUILDFLAG(IS_BSD)
   s.OutputToStream(&os);
 #else
   os << "StackTrace::OutputToStream not implemented.";
