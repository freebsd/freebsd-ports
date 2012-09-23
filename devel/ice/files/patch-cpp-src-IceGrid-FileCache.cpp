--- cpp.orig/src/IceGrid/FileCache.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/IceGrid/FileCache.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -195,15 +195,12 @@ FileCache::read(const string& file, Ice::Long offset, int size, Ice::Long& newOf
 
         totalSize += lineSize;
         lines.push_back(line);
-#if defined(_MSC_VER) && (_MSC_VER < 1300)
-        if(is.eof())
+        
+        if(is.eof() || is.fail())
         {
             newOffset += line.size();
         }
         else
-#else
-        if(!is.fail())
-#endif
         {
             newOffset = is.tellg();
         }
