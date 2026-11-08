--- kent/src/hg/inc/hui.h.orig	2026-08-31 20:04:01 UTC
+++ kent/src/hg/inc/hui.h
@@ -1607,7 +1607,7 @@ int defaultFieldLocation(char *field);
 /* Sometimes we get bigBed filters with field names that are not in the AS file.  
  * Try to guess what the user means. */
 
-void printInfoIconSvg();
+void printInfoIconSvg(char *color);
 /* Print just info icon (i) as svg to stdout */
 
 void printInfoIconColor(char *mouseover, char *color);
