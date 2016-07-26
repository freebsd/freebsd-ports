--- src/main.c.orig	2006-12-17 18:01:22 UTC
+++ src/main.c
@@ -120,6 +120,7 @@ int main(int argc, char *argv[])
 		}
 	}
 
+	gtk_set_locale();
 	gtk_init(&argc, &argv);
 
 	if (argc > 1)
