--- src/basic_util.sml.orig	Sun Jan 13 18:28:51 2008
+++ src/basic_util.sml	Sun Jan 13 18:28:13 2008
@@ -132,7 +132,7 @@
 	   open Substring 
        in
 	   fun breakAtDot s = 
-	       let val (hd, tl) = splitl (not o isDot) (all s)
+	       let val (hd, tl) = splitl (not o isDot) (full s)
 	       in  (string hd, string (triml 1 tl))
 	       end
        end
@@ -150,7 +150,7 @@
 	   else Int.toString s	  
 
        fun all p str = Substring.foldl (fn (c, r)=> (p c) andalso r)
-	                                true (Substring.all str) 
+	                                true (Substring.full str) 
 
        (* Adaptstring converts double quotes and other special characters 
 	* into properly escaped sequences, to insure the string is to
