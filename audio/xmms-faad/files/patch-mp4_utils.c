--- mp4_utils.c.orig	2004-10-18 05:44:51.000000000 +0900
+++ mp4_utils.c	2009-02-12 02:53:15.000000000 +0900
@@ -3,15 +3,22 @@
 */
 
 #include "mp4ff.h"
-#include "faad.h"
+#include "neaacdec.h"
 
 #include <gtk/gtk.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+
+#if defined(HAVE_BMP)
+#include <bmp/plugin.h>
+#include <bmp/titlestring.h>
+#include <bmp/util.h>
+#else
 #include <xmms/plugin.h>
 #include <xmms/titlestring.h>
 #include <xmms/util.h>
+#endif /*HAVE_BMP*/
 
 const char *mp4AudioNames[]=
   {
