--- tools/Packer.cpp.orig	2018-08-19 20:16:16 UTC
+++ tools/Packer.cpp
@@ -33,7 +33,7 @@ const char RPATH_SEPERATOR = '/';
 //OS dependent seperator
 const char PATH_SEPERATOR = '/';
 
-bool operator<( DirectoryEntry &de1, DirectoryEntry &de2)
+bool operator<( const DirectoryEntry &de1, const DirectoryEntry &de2)
 {
     return( de1.resourceName < de2.resourceName);
 }
