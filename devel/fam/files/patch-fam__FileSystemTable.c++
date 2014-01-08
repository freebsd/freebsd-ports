--- ./fam/FileSystemTable.c++.orig	2003-04-15 06:21:31.000000000 +0200
+++ ./fam/FileSystemTable.c++	2014-01-03 02:35:10.000000000 +0100
@@ -255,7 +255,6 @@
     //  create_fs_by_name initializes our "root" member variable.
     if (!fs_by_name)
     {   create_fs_by_name();
-	mtab_watcher = new InternalClient(mtab_name, mtab_event_handler, NULL);
     }
 
     cr.become_user();
