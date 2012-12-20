--- backend/niash.c.orig	2006-02-04 12:34:28.000000000 +0100
+++ backend/niash.c	2007-02-21 15:38:12.000000000 +0100
@@ -89,7 +89,9 @@ typedef enum
   optLamp,
 
   optCalibrate,
-  optGamma                      /* analog gamma = single number */
+  optGamma,                     /* analog gamma = single number */
+/* have optEndOfList only to define arrays with sufficient size */
+  optEndOfList
 } EOptionIndex;
 
 
@@ -105,8 +107,8 @@ typedef union
 
 typedef struct
 {
-  SANE_Option_Descriptor aOptions[optLast];
-  TOptionValue aValues[optLast];
+  SANE_Option_Descriptor aOptions[optEndOfList];
+  TOptionValue aValues[optEndOfList];
 
   TScanParams ScanParams;
   THWParams HWParams;
