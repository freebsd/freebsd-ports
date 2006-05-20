--- server/dda/voxware/config.c	Fri Jul 12 00:44:16 2002
+++ server/dda/voxware/config.c	Mon Oct 10 10:25:22 2005
@@ -6,4 +6,5 @@
 
 #include <fcntl.h>
+#include <inttypes.h>
 #include "nasconf.h"
 #include "config.h"
@@ -27,5 +28,5 @@
     {
     case CONF_SET_SECTION:
-      num = (int) value;
+      num = (intptr_t) value;
 
       if (num == INPUTSECTION)
@@ -40,10 +41,10 @@
 
     case FORCERATE :
-      num = (int) value;
+      num = (intptr_t) value;
       confStat->forceRate = num ;
       break;
 
     case GAIN :
-      num = (int) value;
+      num = (intptr_t) value;
       /* the default is 50, so if it's just out of range, don't
 	 reset it */
@@ -56,10 +57,10 @@
 
     case AUTOOPEN :
-      num = (int) value;
+      num = (intptr_t) value;
       confStat->autoOpen = num;
       break;
 
     case READWRITE :
-      num = (int) value;
+      num = (intptr_t) value;
       if (confStat == &sndStatIn) {
 	confStat->howToOpen = (num ? O_RDWR : O_RDONLY);
@@ -85,5 +86,5 @@
 
     case WORDSIZE:
-      num = (int) value;
+      num = (intptr_t) value;
 
       if (num != 8 && num != 16) 
@@ -97,5 +98,5 @@
 
     case FRAGSIZE:
-      num = (int) value;
+      num = (intptr_t) value;
 
       {
@@ -122,5 +123,5 @@
 
     case MINFRAGS:
-      num = (int) value;
+      num = (intptr_t) value;
 
       if (num < 2 || num > 32) 
@@ -137,5 +138,5 @@
 
     case MAXFRAGS:
-      num = (int) value;
+      num = (intptr_t) value;
 
       if (num < 2 || num > 32) 
@@ -152,5 +153,5 @@
 
     case NUMCHANS:
-      num = (int) value;
+      num = (intptr_t) value;
 
       if (num != 1 && num != 2) 
@@ -164,5 +165,5 @@
 
     case MAXRATE:
-      num = (int) value;
+      num = (intptr_t) value;
 
       confStat->maxSampleRate = num;
@@ -170,5 +171,5 @@
 
     case MINRATE:
-      num = (int) value;
+      num = (intptr_t) value;
 
       confStat->minSampleRate = num;
@@ -176,5 +177,5 @@
 
     case MIXERINIT:
-      num = (int) value;
+      num = (intptr_t) value;
 
       VOXMixerInit = num;
