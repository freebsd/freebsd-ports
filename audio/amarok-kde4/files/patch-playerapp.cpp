--- amarok/amarok/playerapp.cpp.orig	Fri Mar  5 22:15:10 2004
+++ amarok/amarok/playerapp.cpp	Tue Mar 16 21:51:00 2004
@@ -298,14 +298,18 @@
     ::strcpy( &local.sun_path[0], path );
     ::unlink( path );
 
-    int len = ::strlen( local.sun_path ) + sizeof( local.sun_family );
+    int len = sizeof( local );
 
     if ( ::bind( m_sockfd, (struct sockaddr*) &local, len ) == -1 ) {
         kdWarning() << k_funcinfo << " bind() error\n";
+        ::close ( m_sockfd );
+        m_sockfd = -1;
         return;
     }
     if ( ::listen( m_sockfd, 1 ) == -1 ) {
         kdWarning() << k_funcinfo << " listen() error\n";
+	::close ( m_sockfd );
+        m_sockfd = -1;
         return;
     }
 
