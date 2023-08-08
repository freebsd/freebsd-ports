--- atc/update.c.orig	2020-02-26 16:22:47 UTC
+++ atc/update.c
@@ -284,7 +284,7 @@ next_plane(void)
 					break;
 				}
 	} while (found && last_plane != start_plane);
-	if (last_plane == start_plane)
+	if (found)
 		return (-1);
 	return (last_plane);
 }
