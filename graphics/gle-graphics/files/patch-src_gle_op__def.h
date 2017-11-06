--- src/gle/op_def.h.orig	2011-10-26 21:10:54 UTC
+++ src/gle/op_def.h
@@ -40,7 +40,7 @@ struct op_key {
 	char name[256];
 	int typ;
 	int pos;
-	int idx;
+	signed long idx;
 };
 
 #define typ_end     0
