
$FreeBSD$

--- maneditop.c	2001/07/17 15:14:39	1.1
+++ maneditop.c	2001/07/17 15:16:23
@@ -242,9 +242,7 @@
 		/* Not exist, so need to create a new one. */
 		rmkdir(
 		    tmp_dir_rtn,
-		    S_IRUSR | S_IWUSR | S_IXUSR |
-                    S_IRGRP | S_IXGRP |
-		    S_IROTH | S_IXOTH
+		    S_IRUSR | S_IWUSR | S_IXUSR
 		);
 	    }
 	}
