--- src/main.c.orig	2006-12-18 03:01:22.000000000 +0900
+++ src/main.c	2009-03-09 02:20:45.000000000 +0900
@@ -120,6 +120,7 @@
 		}
 	}
 
+	gtk_set_locale();
 	gtk_init(&argc, &argv);
 
 	if (argc > 1)
