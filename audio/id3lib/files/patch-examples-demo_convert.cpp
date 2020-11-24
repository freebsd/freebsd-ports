--- examples/demo_convert.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_convert.cpp
@@ -84,7 +84,7 @@ void DisplayTags(ostream &os, luint nTags)
   }
 }
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   flags_t ulFlag = ID3TT_ALL;
   gengetopt_args_info args;
