--- binutils/arparse.y.orig	Sun Jul 11 22:02:15 1999
+++ binutils/arparse.y	Sun Feb  2 10:44:48 2003
@@ -74,6 +74,7 @@
 
 command_line:
 		command NEWLINE { prompt(); }
+	;
 
 command:
 		open_command	
