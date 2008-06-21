--- src/com_state_pipe.sml.orig	Fri Mar 30 23:39:06 2001
+++ src/com_state_pipe.sml	Sun Jan 13 13:40:19 2008
@@ -145,7 +143,7 @@
 
 
   fun getEvent () = 
-      TextIO.inputLine(getWishIn()) 
+      valOf (TextIO.inputLine(getWishIn()))
       handle Option.Option => "" (* wish has been closed in the meantime *) 
   
   fun eval ps =  
