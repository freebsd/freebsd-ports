--- ui_x.c.orig	2000-10-30 22:15:31 UTC
+++ ui_x.c
@@ -177,6 +177,12 @@ int main(int argc, char *argv[])
 	return 1;
     }
 
+    if (romfile == NULL) {
+	printf("rom not specified.\n");
+	usage(argv[0]);
+	return 1;
+    }
+
     initialize_window(display);
 
     activate_system(system_type, romfile);
