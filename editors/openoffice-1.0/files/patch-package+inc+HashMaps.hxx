--- package/inc/HashMaps.hxx.orig	Tue Oct 30 14:52:18 2001
+++ package/inc/HashMaps.hxx	Wed Jun 12 23:10:42 2002
@@ -79,7 +79,7 @@
 };
 
 class ZipPackageFolder;
-class ContentInfo;
+class ZipContentInfo;
 
 typedef std::hash_map < rtl::OUString, 
 						ZipPackageFolder *,
@@ -87,7 +87,7 @@
 						eqFunc > FolderHash;
 
 typedef std::hash_map < rtl::OUString, 
-						vos::ORef < ContentInfo >,
+						vos::ORef < ZipContentInfo >,
 						::rtl::OUStringHash, 
 						eqFunc > ContentHash;
 
