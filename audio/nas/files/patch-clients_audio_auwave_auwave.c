--- clients/audio/auwave/auwave.c	Thu Apr  7 15:08:14 2005
+++ clients/audio/auwave/auwave.c	Mon Oct 10 11:26:40 2005
@@ -28,4 +28,5 @@
  */
 
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -237,5 +238,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
 
     AuElementParameters parms;
@@ -259,5 +260,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
     AuElementParameters parms;
     char            buf[10];
@@ -284,5 +285,5 @@
 {
     GlobalDataPtr   g = (GlobalDataPtr) gp;
-    int             value = (int) valuep;
+    intptr_t        value = (intptr_t) valuep;
     AuDeviceAttributes da;
 
