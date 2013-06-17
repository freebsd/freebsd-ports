--- SelFile/Draw.c.orig
+++ SelFile/Draw.c
@@ -189,7 +189,7 @@
 	}
 }
 
-static
+static void
 SFdeleteEntry(dir, entry)
 	SFDir	*dir;
 	SFEntry	*entry;
