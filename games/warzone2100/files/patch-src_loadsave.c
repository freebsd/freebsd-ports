--- src/loadsave.c.orig	Wed Jul 27 13:33:56 2005
+++ src/loadsave.c	Thu Sep 22 15:40:54 2005
@@ -341,7 +341,8 @@
 				}
 			}
 		}
-		closedir(d);
+		if (d)
+			closedir(d);
 	}
 #endif
 	bLoadSaveUp = TRUE;
@@ -444,7 +445,8 @@
 			DeleteFile(entry->d_name);
 		}
 
-		closedir(d);
+		if (d)
+			closedir(d);
 	}
 #endif
 
