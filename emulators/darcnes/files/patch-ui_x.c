--- ui_x.c.orig	Mon Oct 30 23:15:31 2000
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
