--- ../sal/workben/getlocaleinfotest.cxx	Sun Mar 10 23:42:26 2002
+++ ../sal/workben/getlocaleinfotest.cxx	Sun Mar 10 23:42:45 2002
@@ -63,7 +63,7 @@
 #include <osl/nlsupport.h>
 #include <rtl/ustring.hxx>
 
-int _cdecl main( int argc, char * argv[] )
+int main( int argc, char * argv[] )
 {
     rtl::OUString lang = rtl::OUString::createFromAscii( "de" );
     rtl::OUString country = rtl::OUString::createFromAscii( "DE" );
