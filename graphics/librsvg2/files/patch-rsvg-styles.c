--- rsvg-styles.c.orig	Tue Mar 23 23:04:27 2004
+++ rsvg-styles.c	Tue Mar 23 23:04:36 2004
@@ -553,16 +553,16 @@
 	if (status != CR_OK)
         {
 			g_warning ("Error setting CSS SAC handler\n");
-			cr_parser_destroy (parser);			
 			cr_doc_handler_destroy (css_handler);
+			cr_parser_destroy (parser);			
 			return;
         }        
 	
 	status = cr_parser_set_use_core_grammar (parser, FALSE);
 	status = cr_parser_parse (parser);
 	
-	cr_parser_destroy (parser);
 	cr_doc_handler_destroy (css_handler);
+	cr_parser_destroy (parser);
 }
 
 #else /* !HAVE_LIBCROCO */
