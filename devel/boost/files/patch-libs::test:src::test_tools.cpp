--- libs/test/src/test_tools.cpp.orig	Tue Feb 17 16:31:56 2004
+++ libs/test/src/test_tools.cpp	Tue Feb 17 16:32:10 2004
@@ -191,7 +191,7 @@
 void
 print_log_value<char>::operator()( std::ostream& ostr, char t )
 {
-    if( std::isprint( t ) )
+    if( isprint( t ) )
         ostr << '\'' << t << '\'';
     else
         ostr << std::hex 
