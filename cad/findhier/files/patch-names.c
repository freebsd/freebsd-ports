--- names.c.orig	Sun Apr 29 00:54:55 2007
+++ names.c	Sun Apr 29 00:55:01 2007
@@ -116,7 +116,7 @@
 	}
 #ifndef _UNIX_
 	strlwr(dp);
-#endif _UNIX_
+#endif /* _UNIX_ */
 	/* extension() will corrupt dp on purpose */
 	if (!strcmp(extension(dp),EXT+1)) create(dp);
 }
