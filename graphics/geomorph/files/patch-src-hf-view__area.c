--- src/hf/view_area.c.orig	2010-07-31 07:31:37.000000000 +0400
+++ src/hf/view_area.c	2013-12-24 08:09:42.420751997 +0400
@@ -20,6 +20,7 @@
 
  //	Modified 2005-01-09 for removing double buffering (now auto with GTK2) PSTG
  
+#include "../utils/x_alloc.h"
 #include "view_area.h"
 #include <stdlib.h>
 #include <stdio.h>
