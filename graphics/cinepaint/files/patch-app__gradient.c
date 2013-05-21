--- app/gradient.c.orig
+++ app/gradient.c
@@ -5452,7 +5452,7 @@
           g_message (_("Corrupt segment %d in gradient file '%s'."),
                      i, filename);
           fclose (file);
-          return NULL;
+          return;
         }
 #else
 		if (sscanf(line, "%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%d%d",
