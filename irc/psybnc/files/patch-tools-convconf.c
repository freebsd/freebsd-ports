--- tools/convconf.c.orig	Sat Dec 18 15:03:56 2004
+++ tools/convconf.c	Sat Dec 18 15:05:01 2004
@@ -77,7 +77,7 @@
 		   fprintf(outfile,"%s.%s.%s\n",fname,section,buf);
 		}
 	}
-	next:
+	next:;
     }
     return 0x0;
 }
