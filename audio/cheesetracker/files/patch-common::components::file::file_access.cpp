--- common/components/file/file_access.cpp.orig	Fri Sep 17 10:37:01 2004
+++ common/components/file/file_access.cpp	Fri Sep 17 10:37:23 2004
@@ -164,7 +164,7 @@
 
 	for (i=0;i<length;i++) {
 
-		get_byte((Uint8)aux_char);
+		get_byte((Uint8&)aux_char);
 		aux_string=aux_string+aux_char;
 	}
 
