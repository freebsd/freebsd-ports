
$FreeBSD$

--- src/files.cc.orig	Tue Aug 13 22:16:33 2002
+++ src/files.cc	Tue Aug 13 22:16:54 2002
@@ -360,7 +360,7 @@
 {
     CFunctionDebug( "CFile::normalize" );
 
-    if ( path.find( "//" ) == (unsigned int) -1)
+    if ( path.find( "//" ) == std::string::npos)
     {
 	return( path );
     }
