--- ./qcommon/cmd.c.orig	Tue May 16 15:20:10 2006
+++ ./qcommon/cmd.c	Tue May 16 15:20:10 2006
@@ -215,8 +215,10 @@
 			if (text[i] == '\n')
 				break;
 		}
-			
-				
+		// sku - removed potentional buffer overflow vulnerability
+		if( i > sizeof( line ) - 1 ) {
+			i = sizeof( line ) - 1;
+		}
 		memcpy (line, text, i);
 		line[i] = 0;
 		
@@ -657,7 +659,8 @@
 		{
 			int		l;
 
-			strcpy (cmd_args, text);
+			// sku - removed potentional buffer overflow vulnerability
+			strncpy( cmd_args, text, sizeof( cmd_args ) );
 
 			// strip off any trailing whitespace
 			l = strlen(cmd_args) - 1;
