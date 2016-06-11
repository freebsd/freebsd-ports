--- src/xpdf/xpdf/Object.h.orig	2009-09-11 12:04:43 UTC
+++ src/xpdf/xpdf/Object.h
@@ -206,7 +206,7 @@ public:
 private:
 
   ObjType type;			// object type
-  mutable union {		// value for each type:
+  union {		// value for each type:
     GBool booln;		//   boolean
     int intg;			//   integer
     double real;		//   real
