--- rebler.cpp.orig	Mon Aug  6 22:59:36 2001
+++ rebler.cpp	Sun Apr 13 04:09:49 2003
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
@@ -303,7 +304,6 @@
             case CodecInfo::Plugin: cerr << "Plugin "; break;
             case CodecInfo::Win32:  cerr << "Win32  "; break;
             case CodecInfo::DShow_Dec: cerr << "DShow_Dec"; break;
-            case CodecInfo::DShow_Enc: cerr << "DShow_Enc"; break;
             default:
                 cerr << "Unknown";
                 break;
@@ -325,8 +325,8 @@
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
@@ -338,8 +338,8 @@
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
