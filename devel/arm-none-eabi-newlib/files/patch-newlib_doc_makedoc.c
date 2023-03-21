--- newlib/doc/makedoc.c.orig	2023-03-21 04:12:20 UTC
+++ newlib/doc/makedoc.c
@@ -1317,11 +1317,11 @@ DEFUN(compile, (string), 
 		     /* Got a number, embedd the magic push number
 			function */
 		     add_to_definition(ptr, push_number);
-		     add_to_definition(ptr, atol(word));
+		     add_to_definition(ptr, (stinst_type)atol(word));
 		     break;
 		   default:
 		     add_to_definition(ptr, call);
-		     add_to_definition(ptr, lookup_word(word));
+		     add_to_definition(ptr, (stinst_type)lookup_word(word));
 		 }
 
 		string = nextword(string, &word);		     
