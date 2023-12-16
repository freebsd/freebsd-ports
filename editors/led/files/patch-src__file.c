--- src/file.c.orig	2002-02-16 16:41:11 UTC
+++ src/file.c
@@ -192,6 +192,8 @@ forcenl:
 			putc('\r', fp);
 		putc('\n', fp);
 	}
+	fflush(fp);
+	fsync(fileno(fp));
 
 	return 0;
 }
