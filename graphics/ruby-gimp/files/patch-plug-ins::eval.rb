--- plug-ins/eval.rb.orig	Tue Feb 27 20:08:13 2001
+++ plug-ins/eval.rb	Thu Mar  1 01:29:43 2001
@@ -13,7 +13,7 @@
 	 "",
 	 [
 	   [RF_STRING, "code", "Code to eval", "", true],
-	 ],
+	 ]
 ) { |text|
   eval(text)
 }
