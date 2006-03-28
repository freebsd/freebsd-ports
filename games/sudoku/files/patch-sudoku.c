--- sudoku.c.orig	Tue Mar 28 08:55:35 2006
+++ sudoku.c	Tue Mar 28 08:55:55 2006
@@ -1837,7 +1837,7 @@
 
     /* Read character input (raw processing mode) */
     i = strlen( userfile );
-    while( '\r' != ( ch = getkey( ) ) )
+    while( '\n' != ( ch = getkey( ) ) )
     {
         if( 0x08 == ch || VKEY_LEFT == ch ) /* destructive backspace */
         {
