--- integrator.cpp.orig	2008-05-30 00:12:59.000000000 +0400
+++ integrator.cpp	2008-05-30 00:15:20.000000000 +0400
@@ -190,7 +190,7 @@
   qtwatch->watch = watch;
 
   int flags = dbus_watch_get_flags( watch );
-  int fd = dbus_watch_get_fd( watch );
+  int fd = dbus_watch_get_unix_fd( watch );
 
   if ( flags & DBUS_WATCH_READABLE ) {
     qtwatch->readSocket = new QSocketNotifier( fd, QSocketNotifier::Read, this );
@@ -207,7 +207,7 @@
 
 void Integrator::removeWatch( DBusWatch *watch )
 {
-  int key = dbus_watch_get_fd( watch );
+  int key = dbus_watch_get_unix_fd( watch );
 
   Watch *qtwatch = m_watches.take( key );
 
