diff -ruN fam/FileSystemTable.c++ fam/FileSystemTable.c++
--- fam/FileSystemTable.c++	Wed May 29 00:17:42 2002
+++ fam/FileSystemTable.c++	Sat Jun  8 16:31:07 2002
@@ -256,7 +256,10 @@
     //  create_fs_by_name initializes our "root" member variable.
     if (!fs_by_name)
     {   create_fs_by_name();
+#if !defined(__FreeBSD__)
+	/* there is no mtab "file" in freebsd! */
 	mtab_watcher = new InternalClient(mtab_name, mtab_event_handler, NULL);
+#endif
     }
 
     cr.become_user();
