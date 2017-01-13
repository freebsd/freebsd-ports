--- parser.y.orig	2003-12-09 16:45:41 UTC
+++ parser.y
@@ -110,7 +110,7 @@ image_ranges:
 
 
 input_file_clause:
-	FILE_KEYWORD STRING  ';'  { input_set_file ($2) } ;
+	FILE_KEYWORD STRING  ';'  { input_set_file ($2); } ;
 
 image_clause:
 	IMAGE INTEGER ';' { range_t range = { $2, $2 }; input_images (range); } ;
@@ -119,7 +119,7 @@ images_clause:
 	IMAGES image_ranges ';' ;
 
 rotate_clause:
-	ROTATE INTEGER ';' { input_set_rotation ($2) } ;
+	ROTATE INTEGER ';' { input_set_rotation ($2); } ;
 
 unit:
 	/* empty */  /* default to INCH */ { $$ = 1.0; }
