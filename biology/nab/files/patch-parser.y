--- tleap/parser.y.orig	Tue Oct 29 13:46:35 2002
+++ tleap/parser.y	Tue Oct 29 13:48:18 2002
@@ -220,6 +220,7 @@
 		{
 			return;
 		}
+	;
 
 line    :       LENDOFCOMMAND
 	|	instruct
