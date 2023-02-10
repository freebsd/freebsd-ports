--- tools/elfdeps.c.orig	2023-01-16 16:44:45.666870000 -0500
+++ tools/elfdeps.c	2023-01-16 16:44:57.548011000 -0500
@@ -84,7 +84,7 @@
     if (ehdr->e_ident[EI_CLASS] == ELFCLASS64) {
 	switch (ehdr->e_machine) {
 	case EM_ALPHA:
-	case EM_FAKE_ALPHA:
+	case EM_ALPHA_STD:
 	    /* alpha doesn't traditionally have 64bit markers */
 	    break;
 	default:
