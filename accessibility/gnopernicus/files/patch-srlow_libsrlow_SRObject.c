--- srlow/libsrlow/SRObject.c.orig	Mon Feb 28 17:11:27 2005
+++ srlow/libsrlow/SRObject.c	Mon Feb 28 17:11:41 2005
@@ -4206,9 +4206,10 @@
     offset = AccessibleText_getCaretOffset (acc_text);
     if (offset == AccessibleText_getCharacterCount (acc_text) && offset > 0)
 	{
+		char *ret;
 		offset--;
 		last = TRUE;/*the char is the last char in the text*/
-		char *ret = AccessibleText_getTextBeforeOffset (acc_text, offset+1, 
+		ret = AccessibleText_getTextBeforeOffset (acc_text, offset+1, 
 					SPI_TEXT_BOUNDARY_LINE_START, &line_start_offset, &line_end_offset);
 		SPI_freeString (ret);
 		if (offset == line_start_offset && offset > 0)
