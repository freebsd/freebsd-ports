--- src/binkp.h.orig	2020-08-20 17:16:42 UTC
+++ src/binkp.h
@@ -43,7 +43,7 @@
 
 
 /* messages */
-enum {
+static enum {
     BPM_NONE = 99,		/* No available data */
     BPM_DATA = 98,		/* Binary data */
     BPM_NUL = 0,		/* Site information */
