--- fam/FileSystemTable.c++.orig	Fri Aug 11 22:27:15 2006
+++ fam/FileSystemTable.c++	Fri Aug 11 22:28:29 2006
@@ -255,7 +255,6 @@
     //  create_fs_by_name initializes our "root" member variable.
     if (!fs_by_name)
     {   create_fs_by_name();
-	mtab_watcher = new InternalClient(mtab_name, mtab_event_handler, NULL);
     }
 
     cr.become_user();
