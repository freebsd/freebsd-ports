--- amarok/amarok/loader/loader.cpp.orig	Fri Mar  5 22:15:11 2004
+++ amarok/amarok/loader/loader.cpp	Tue Mar 16 21:48:30 2004
@@ -156,10 +156,11 @@
     path += "/.kde/share/apps/amarok/.loader_socket";
     ::strcpy( &local.sun_path[0], path );
 
-    int len = ::strlen( local.sun_path ) + sizeof( local.sun_family );
+    int len = sizeof( local );
 
     if ( ::connect( fd, (struct sockaddr*) &local, len ) == -1 ) {
 //         qDebug( "[Loader::tryConnect()] connect() failed" );
+        ::close ( fd );
         return -1;
     }
 
