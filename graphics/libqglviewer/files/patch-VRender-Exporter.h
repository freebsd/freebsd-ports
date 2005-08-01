--- VRender/Exporter.h.orig	Thu Jun 30 02:06:00 2005
+++ VRender/Exporter.h	Tue Jul  5 12:41:58 2005
@@ -49,6 +49,8 @@
 
 // Set of classes for exporting in various formats, like EPS, XFig3.2, SVG.
 
+#include <stdio.h>
+
 #include "Primitive.h"
 
 namespace vrender
