--- server/dda/voxware/config.c.orig	2007-06-16 23:03:22.000000000 +0400
+++ server/dda/voxware/config.c	2008-05-14 22:49:23.000000000 +0400
@@ -5,6 +5,7 @@
  */
 
 #include <fcntl.h>
+#include <inttypes.h>
 #include "nasconf.h"
 #include "config.h"
 #include "aulog.h"
@@ -27,7 +28,7 @@
 
     switch (token) {
     case CONF_SET_SECTION:
-        num = (int) value;
+        num = (intptr_t) value;
 
         if (num == INPUTSECTION) {      /* we're in the input section */
             confStat = &sndStatIn;
@@ -37,12 +38,12 @@
         break;
 
     case FORCERATE:
-        num = (int) value;
+        num = (intptr_t) value;
         confStat->forceRate = num;
         break;
 
     case GAINSCALE:
-        num = (int) value;
+        num = (intptr_t) value;
         if (num < 0 || num > 100)
             osLogMsg("config: gain scaling must be within the range 0-100\n");
         else
@@ -50,7 +51,7 @@
         break;
 
     case GAIN:
-        num = (int) value;
+        num = (intptr_t) value;
         /* the default is 50, so if it's just out of range, don't
            reset it */
         if (num < 0 || num > 100)
@@ -61,12 +62,12 @@
         break;
 
     case AUTOOPEN:
-        num = (int) value;
+        num = (intptr_t) value;
         confStat->autoOpen = num;
         break;
 
     case READWRITE:
-        num = (int) value;
+        num = (intptr_t) value;
         if (confStat == &sndStatIn) {
             confStat->howToOpen = (num ? O_RDWR : O_RDONLY);
         } else {
@@ -89,7 +90,7 @@
         break;
 
     case WORDSIZE:
-        num = (int) value;
+        num = (intptr_t) value;
 
         if (num != 8 && num != 16) {
             osLogMsg("config: Wordsize (%d) not 8 or 16, setting to 8\n",
@@ -100,7 +101,7 @@
         break;
 
     case FRAGSIZE:
-        num = (int) value;
+        num = (intptr_t) value;
 
         {
             int i, j, k;
@@ -125,7 +126,7 @@
         break;
 
     case MINFRAGS:
-        num = (int) value;
+        num = (intptr_t) value;
 
         if (num < 2 || num > 32) {
             osLogMsg("config: Minfrags out of range - setting to 2\n");
@@ -138,7 +139,7 @@
         break;
 
     case MAXFRAGS:
-        num = (int) value;
+        num = (intptr_t) value;
 
         if (num < 2 || num > 32) {
             osLogMsg("config: Maxfrags out of range - setting to 32\n");
@@ -151,7 +152,7 @@
         break;
 
     case NUMCHANS:
-        num = (int) value;
+        num = (intptr_t) value;
 
         if (num != 1 && num != 2) {
             osLogMsg("config: Number of channels wrong, setting to 1\n");
@@ -161,25 +162,25 @@
         break;
 
     case MAXRATE:
-        num = (int) value;
+        num = (intptr_t) value;
 
         confStat->maxSampleRate = num;
         break;
 
     case MINRATE:
-        num = (int) value;
+        num = (intptr_t) value;
 
         confStat->minSampleRate = num;
         break;
 
     case MIXERINIT:
-        num = (int) value;
+        num = (intptr_t) value;
 
         VOXMixerInit = num;
         break;
 
     case REINITMIXER:
-        num = (int) value;
+        num = (intptr_t) value;
 
         VOXReInitMixer = num;
         break;
