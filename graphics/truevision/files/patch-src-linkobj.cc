--- src/linkobj.cc.orig	Sun Feb 27 02:02:13 2005
+++ src/linkobj.cc	Wed Mar 16 22:15:22 2005
@@ -94,7 +94,7 @@
 	glScalef( a, b, c );
 	rotation->gl_rotate();
 
-	link->get_current()->display( false );
+	link->get_current()->display( NULL, false );
 
 	glPopMatrix();
 	list.end();
