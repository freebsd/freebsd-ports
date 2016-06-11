--- src/xpdf/xpdf/Object.h.orig	2015-08-23 03:17:00.826883000 +0900
+++ src/xpdf/xpdf/Object.h	2015-08-23 03:17:15.658920000 +0900
@@ -206,7 +206,7 @@
 private:
 
   ObjType type;			// object type
-  mutable union {		// value for each type:
+  union {		// value for each type:
     GBool booln;		//   boolean
     int intg;			//   integer
     double real;		//   real
