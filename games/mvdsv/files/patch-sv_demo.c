--- sv_demo.c.orig	Tue Jun  3 17:50:02 2003
+++ sv_demo.c	Tue Jun  3 17:53:09 2003
@@ -607,12 +607,12 @@
 {
 	if (!USACACHE)
 	{
-		dwrite = &fwrite;
+		dwrite = (void *)&fwrite;
 		demo.dest = demo.file;
 		demo.disk = true;
 	} else 
 	{
-		dwrite = &memwrite;
+		dwrite = (void *)&memwrite;
 		demo.mfile = svs.demomem;
 		demo.dest = &demo.mfile;
 	}
