--- ./src/config.sig.orig	Fri Mar 30 23:39:07 2001
+++ src/config.sig	Sun Jan 13 11:10:08 2008
@@ -50,6 +50,8 @@
 
         val showReal           : real -> string
 
+	val showColor          : BasicTypes.Color -> string
+
 	val winConfEq          : BasicTypes.WinConfigure -> 
 	                         BasicTypes.WinConfigure -> bool
 
