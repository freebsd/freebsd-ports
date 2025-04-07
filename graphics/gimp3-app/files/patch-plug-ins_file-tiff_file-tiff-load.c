--- plug-ins/file-tiff/file-tiff-load.c.orig	2023-07-05 14:00:47 UTC
+++ plug-ins/file-tiff/file-tiff-load.c
@@ -61,6 +61,7 @@
 
 #include "libgimp/stdplugins-intl.h"
 
+#include <math.h>
 
 #define PLUG_IN_ROLE "gimp-file-tiff-load"
 
