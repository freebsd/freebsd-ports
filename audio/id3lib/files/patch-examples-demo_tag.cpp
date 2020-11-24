--- examples/demo_tag.cpp.orig	2003-03-02 00:23:00 UTC
+++ examples/demo_tag.cpp
@@ -46,7 +46,7 @@ void DisplayTags(ostream &os, luint nTags)
     os << "v2";
 }
 
-int main( unsigned int argc, char * const argv[])
+int main( int argc, char * const argv[])
 {
   int ulFlag = ID3TT_ID3;
   ID3D_INIT_DOUT();
