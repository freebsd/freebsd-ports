--- htapp.cc.orig	Sat Jul 19 05:35:07 2003
+++ htapp.cc	Sat Jul 19 05:39:02 2003
@@ -2028,7 +2028,7 @@
 		get_stdbounds_tool(&b);
 
 		ht_project_window *project_window=new ht_project_window();
-		project_window->init(&b, "project window", FS_KILLER | FS_TITLE | FS_NUMBER | FS_MOVE | FS_RESIZE, 0, &(ht_project*)project);
+		project_window->init(&b, "project window", FS_KILLER | FS_TITLE | FS_NUMBER | FS_MOVE | FS_RESIZE, 0, (ht_project**)&project);
 
 		bounds k = b;
 		k.x = b.w-2;
