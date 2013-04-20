--- app/client/MediaDevices/IpodDevice_linux.cpp.orig	2013-03-20 13:01:09.893307620 +0000
+++ app/client/MediaDevices/IpodDevice_linux.cpp	2013-03-20 13:01:18.972308216 +0000
@@ -34,7 +34,7 @@
 extern "C"
 {
     #include <gpod/itdb.h>
-    #include <glib/glist.h>
+    #include <glib.h>
 }
 
 IpodTracksFetcher::IpodTracksFetcher( Itdb_iTunesDB *itdb, QSqlDatabase scrobblesdb,
