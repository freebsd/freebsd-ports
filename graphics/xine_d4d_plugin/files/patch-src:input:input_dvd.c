--- src/input/input_dvd.c.orig	Sun Jun  2 04:15:05 2002
+++ src/input/input_dvd.c	Sun Jun  2 04:15:08 2002
@@ -1132,7 +1132,7 @@
   config_values_t    *config;
   int                 i, fd;
 
-  if (iface != 6) {
+  if (iface != 7) {
     printf ("input_d4d: input plugin doesn't support plugin API version %d.\n",
             iface);
     return NULL;
