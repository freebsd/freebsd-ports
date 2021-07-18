--- src/fcdump/fc_dump.c.orig	2021-05-10 22:05:35 UTC
+++ src/fcdump/fc_dump.c
@@ -597,7 +597,7 @@ int main(int argc, char *argv[])
                 if (strcmp(argv[i], "-demangle-gnu") == 0)
             {/* demangle names */
                 demangle = 1;
-                style = DMGL_GNU;
+                style = DMGL_GNU_V3;
             }
             else
                 if (strcmp(argv[i], "-demangle-java") == 0)
