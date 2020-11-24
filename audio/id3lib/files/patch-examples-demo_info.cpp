--- examples/demo_info.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_info.cpp
@@ -309,7 +309,7 @@ void PrintInformation(const ID3_Tag &myTag)
 
 #define DEBUG
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   ID3D_INIT_DOUT();
 
