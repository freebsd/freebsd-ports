--- common/UCvsFolders.cpp.orig	Fri Aug  2 17:05:02 2002
+++ common/UCvsFolders.cpp	Sun Aug 24 13:42:55 2003
@@ -828,7 +828,7 @@
 		if(fileView != 0L)
 		{
 			ASSERT(fileView->IsKindOf(URUNTIME_CLASS(UCvsFiles)));
-			fileView->ResetView(path);
+			fileView->ResetView( (const char *)path);
 		}
 	}
 
