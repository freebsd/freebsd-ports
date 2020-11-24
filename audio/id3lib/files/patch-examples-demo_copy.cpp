--- examples/demo_copy.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_copy.cpp
@@ -81,7 +81,7 @@ void DisplayTags(ostream &os, luint nTags)
   }
 }
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   int ulFlag = ID3TT_ID3;
   ID3D_INIT_DOUT();
