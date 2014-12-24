$OpenBSD: patch-converter_other_pngtxt_c,v 1.1 2011/07/08 20:36:09 naddy Exp $

Fix build with png-1.5.

--- converter/other/pngtxt.c.orig	Fri Aug 18 21:12:28 2006
+++ converter/other/pngtxt.c	Mon Jul  4 14:21:23 2011
@@ -240,7 +240,8 @@ handleArrayAllocation(png_text **    const arrayP,
 
 
 void 
-pnmpng_read_text (png_info * const info_ptr, 
+pnmpng_read_text (png_struct * png_ptr,
+                  png_info * info_ptr, 
                   FILE *     const tfp, 
                   bool       const ztxt,
                   bool       const verbose) {
@@ -250,6 +251,7 @@ pnmpng_read_text (png_info * const info_ptr, 
     unsigned int commentIdx;
     bool noCommentsYet;
     bool eof;
+    png_textp text_ptr;
     unsigned int allocatedComments;
         /* Number of entries currently allocated for the info_ptr->text
            array 
@@ -257,8 +259,8 @@ pnmpng_read_text (png_info * const info_ptr, 
 
     allocatedComments = 256;  /* initial value */
 
-    MALLOCARRAY(info_ptr->text, allocatedComments);
-    if (info_ptr->text == NULL) 
+    MALLOCARRAY(text_ptr, allocatedComments);
+    if (text_ptr == NULL) 
         pm_error("unable to allocate memory for comment array");
 
     commentIdx = 0;
@@ -273,7 +275,7 @@ pnmpng_read_text (png_info * const info_ptr, 
             if (lineLength == 0) {
                 /* skip this empty line */
             } else {
-                handleArrayAllocation(&info_ptr->text, &allocatedComments,
+                handleArrayAllocation(&text_ptr, &allocatedComments,
                                       commentIdx);
                 if ((textline[0] != ' ') && (textline[0] != '\t')) {
                     /* Line doesn't start with white space, which
@@ -285,7 +287,7 @@ pnmpng_read_text (png_info * const info_ptr, 
                         ++commentIdx;
                     noCommentsYet = FALSE;
 
-                    startComment(&info_ptr->text[commentIdx], 
+                    startComment(&text_ptr[commentIdx], 
                                  textline, lineLength, ztxt);
                 } else {
                     /* Line starts with whitespace, which means it is
@@ -295,20 +297,20 @@ pnmpng_read_text (png_info * const info_ptr, 
                         pm_error("Invalid comment file format: "
                                  "first line is a continuation line! "
                                  "(It starts with whitespace)");
-                    continueComment(&info_ptr->text[commentIdx], 
+                    continueComment(&text_ptr[commentIdx], 
                                     textline, lineLength);
                 }
             }
             strfree(textline);
         }
     } 
-    if (noCommentsYet)
-        info_ptr->num_text = 0;
-    else
-        info_ptr->num_text = commentIdx + 1;
+    if (!noCommentsYet)
+        png_set_text(png_ptr, info_ptr, text_ptr, commentIdx + 1);
 
     if (verbose)
-        pm_message("%d comments placed in text chunk", info_ptr->num_text);
+        pm_message("%d comments placed in text chunk", commentIdx + 1);
+
+    free(text_ptr);
 }
 
 
