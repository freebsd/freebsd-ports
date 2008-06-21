--- ./src/paths.sml.orig	Fri Mar 30 23:39:15 2001
+++ src/paths.sml	Sun Jan 13 11:03:51 2008
@@ -29,13 +29,13 @@
 
 fun fstWidPath s  = 
     let val (m1, m2) = Substring.splitl (not o StringUtil.isDot) 
-	                                (Substring.triml 1 (Substring.all s))
+	                                (Substring.triml 1 (Substring.full s))
     in  (Substring.string m1, Substring.string m2)
     end	
 
 fun lastWidPath p = 
     let val (rp, rw) = Substring.splitr (not o StringUtil.isDot)
-	                                (Substring.all p)
+	                                (Substring.full p)
     in  
 	if (Substring.size rp)= 0 then
 	    ("", Substring.string rw)
