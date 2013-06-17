--- cpp.orig/src/IceGrid/FileCache.cpp	2013-03-11 15:19:12.271195149 +0000
+++ cpp/src/IceGrid/FileCache.cpp	2013-06-01 17:47:48.636196265 +0000
@@ -195,11 +195,11 @@
         // Some eofbit cases will also set failbit. So first
         // check eof.
         //
-        if(is.eof())
+        if(is.eof() || is.fail())
         {
             newOffset += line.size();
         }
-        else if(!is.fail())
+        else
         {
             newOffset = is.tellg();
         }
