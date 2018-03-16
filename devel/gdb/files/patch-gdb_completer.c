--- gdb/completer.c.orig	2018-03-15 16:51:01.106677000 +0100
+++ gdb/completer.c	2018-03-15 16:51:47.055214000 +0100
@@ -2038,7 +2038,7 @@
       /* We don't rely on readline appending the quote char as
 	 delimiter as then readline wouldn't append the ' ' after the
 	 completion.  */
-      char buf[2] = { quote_char () };
+      char buf[2] = { static_cast<char> (quote_char ()) };
 
       match_list[0] = reconcat (match_list[0], match_list[0],
 				buf, (char *) NULL);
