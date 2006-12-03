--- src/re.cc.orig	Tue Jun 19 16:16:29 2001
+++ src/re.cc	Fri Dec  1 18:37:32 2006
@@ -26,7 +26,7 @@
 
 
 // Template instantiations ----------------------------------------------------
-template regex<string>;
+template class regex<string>;
 
 
 
