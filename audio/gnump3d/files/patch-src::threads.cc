
$FreeBSD$

--- src/threads.cc.orig	Sun Jul 14 01:53:50 2002
+++ src/threads.cc	Tue Aug 13 22:15:58 2002
@@ -39,6 +39,7 @@
 #include <errno.h>
 #include <algorithm>
 #include <fstream.h> /* Portability fix: used to be <fstream> */
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <netdb.h>
@@ -248,7 +249,7 @@
      * worry about things like '%2E'.
      *
      */
-    if ( path.find( "/../" ) != (unsigned int)-1 )
+    if ( path.find( "/../" ) != std::string::npos )
     {
 	path = "/";
     }
@@ -278,7 +279,7 @@
     /*
      * Return a playlist of all the files in the given directory.
      */
-    if ( path.find( "/all.m3u" ) != (unsigned int)-1 )
+    if ( path.find( "/all.m3u" ) != std::string::npos )
     {
 	std::string dir;
 	int offset = path.find( "/all.m3u" );
@@ -307,7 +308,7 @@
     /*
      * Return a playlist of all the files in the given directory - Recursively.
      */
-    if ( path.find( "/recurse.m3u" ) !=  (unsigned int)-1 )
+    if ( path.find( "/recurse.m3u" ) !=  std::string::npos )
     {
 	std::string dir;
 	int offset = path.find( "/recurse.m3u" );
@@ -337,7 +338,7 @@
      * Handle streaming a file or a playlist to the client - don't serve
      * the .password file to clients though..
      */
-    if ( path.find( "/.password" ) != (unsigned int)-1 )
+    if ( path.find( "/.password" ) != std::string::npos )
     {
 	std::string errText = "'$PATH' - Not found.";
     
@@ -441,7 +442,7 @@
      * as a result of 'always_stream' being set to 1).
      */
     if ( settings->alwaysStream() && 
-	 ( path.find( ".m3u" ) != (unsigned int)-1 ) )
+	 ( path.find( ".m3u" ) != std::string::npos ) )
     {
 	/* Strip off the '.m3u' suffix */
 	if ( path.size() > 4 )
