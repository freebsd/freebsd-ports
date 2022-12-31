--- display.c.orig	2022-12-31 01:22:36 UTC
+++ display.c
@@ -8,6 +8,11 @@ display_system (void)
 
      FILE *f;
      f = fopen("New.System", "w");
+	 if (f == NULL)
+	 {
+	   perror("New.System");
+	   exit(1);
+	 }
 
      fprintf(f,"                         SYSTEM  CHARACTERISTICS\n");
      fprintf(f,"Mass of central star:          %6.3f solar masses\n", stellar_mass_ratio);
