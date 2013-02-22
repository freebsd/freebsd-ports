commit adfdc14c7ff3dbafe33d315ac2441d46ee9ef8f5
Author: Mitsuru Y <mitsuruy@reallyenglish.com>
Date:   Tue Dec 11 15:18:40 2012 +0900

    make mongorestore be quiet

--- src/mongo/tools/tool.cpp.orig	2013-02-22 13:03:09.000000000 +0900
+++ src/mongo/tools/tool.cpp	2013-02-22 13:03:59.000000000 +0900
@@ -436,7 +436,7 @@
     }
 
     BSONTool::BSONTool( const char * name, DBAccess access , bool objcheck )
-        : Tool( name , access , "" , "" , false ) , _objcheck( objcheck ) {
+        : Tool( name , access , "" , "" , true ) , _objcheck( objcheck ) {
 
         add_options()
         ("objcheck" , "validate object before inserting" )
