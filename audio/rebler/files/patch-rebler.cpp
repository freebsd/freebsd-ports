--- rebler.cpp.orig	Mon Aug  6 21:59:36 2001
+++ rebler.cpp	Wed Mar  6 12:03:42 2002
@@ -29,6 +29,7 @@
 ******************************************************************************/
 
 
+#include <vector>
 #include <string>
 #include <iostream>
 #include <fstream>
@@ -281,8 +282,8 @@
     void dumpCodec( const CodecInfo* ci )
         {
             cerr << "-------------------------------------------" << endl;
-            cerr << "Name       : " << ci->text << endl;
-            cerr << "About      : " << ci->about << endl;
+            cerr << "Name       : " << ci->GetName() << endl;
+            cerr << "About      : " << ci->GetAbout() << endl;
             cerr << "Win32DLL   : " << ci->dll << endl;
 //                cerr << "GUID       : " << ci->guid << endl;
             cerr << "module name: " << ci->modulename << endl;
@@ -325,8 +326,8 @@
                  iter != ci->encoder_info.end();
                  iter++)
             {
-                cerr << "  " << "name  : " << iter->name << endl;
-                cerr << "    " << "about : " << iter->about << endl;
+                cerr << "  " << "name  : " << iter->GetName() << endl;
+                cerr << "    " << "about : " << iter->GetAbout() << endl;
                 cerr << "    " << "kind  : ";
                 switch(iter->kind)
                 {
@@ -338,8 +339,8 @@
                 {
                     cerr << "Select from: ";
                     for( std::vector<std::string>::const_iterator i =
-                             iter->options.begin();
-                         i != iter->options.end();
+                             (std::vector<std::string>::const_iterator)iter->options.begin();
+                         i != (std::vector<std::string>::const_iterator)iter->options.end();
                          i++ )
                     {
                         cerr << *i << " ";
