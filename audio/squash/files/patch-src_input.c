--- src/input.c.orig	2003-12-12 17:24:36 UTC
+++ src/input.c
@@ -1477,7 +1477,7 @@ void do_edit_command( void ) {
     pid = fork();
 
     if( pid == 0 ) { /* the child */
-        execlp( editor, editor, filename, 0 );
+        execlp( editor, editor, filename, NULL );
         /* be safe */
         return;
     }
