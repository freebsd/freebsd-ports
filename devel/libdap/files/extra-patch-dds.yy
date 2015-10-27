--- dds.yy.orig	2014-11-20 20:00:18 UTC
+++ dds.yy
@@ -261,8 +261,8 @@ declaration:  base_type var ';' 
 
 		| grid '{' SCAN_WORD ':'
 		{ 
-		    if (is_keyword(string($3), "array"))
-			part = array; 
+		    if (is_keyword(string($3), "libdap::Part::array"))
+			part = libdap::Part::array; 
 		    else {
 			ostringstream msg;
 			msg << BAD_DECLARATION;
