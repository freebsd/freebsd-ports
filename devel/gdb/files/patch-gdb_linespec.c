--- gdb/linespec.c.orig	2018-03-15 16:52:46.342610000 +0100
+++ gdb/linespec.c	2018-03-15 16:53:18.324077000 +0100
@@ -2912,7 +2912,7 @@
 	     new "quote" char.  */
 	  if (tracker.quote_char ())
 	    {
-	      char quote_char_str[2] = { tracker.quote_char () };
+	      char quote_char_str[2] = { static_cast<char>(tracker.quote_char () )};
 
 	      fn = reconcat (fn, fn, quote_char_str, (char *) NULL);
 	      tracker.set_quote_char (':');
