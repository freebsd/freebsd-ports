--- src/win95/chunk.cpp.orig	2023-01-07 16:38:50 UTC
+++ src/win95/chunk.cpp
@@ -437,7 +437,7 @@ Chunk* Chunk_With_Children::lookup_single_child (const
 
 	if (children)	
 		while	(child_ptr != NULL) {
-			if (strncmp (class_ident, child_ptr->identifier, 8) == NULL)
+			if (strncmp (class_ident, child_ptr->identifier, 8) == 0)
 			{
 				assert (!child_ptr->r_u_miscellaneous());
 				return child_ptr;
