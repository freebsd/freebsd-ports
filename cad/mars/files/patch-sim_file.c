--- sim/file.c.orig	2007-11-23 23:15:16.000000000 +0100
+++ sim/file.c	2007-11-23 23:16:18.000000000 +0100
@@ -252,7 +252,7 @@
 
 #ifndef NoX
 	    if (doXstuff)  {
-	       if (((COMP_OBJECT) c1->co_picture = (COMP_OBJECT)pop_comp_window((COMPONENT *)c1,xpos, ypos)) == (COMP_OBJECT) NULL) {
+	       if (( c1->co_picture = (COMP_OBJECT)pop_comp_window((COMPONENT *)c1,xpos, ypos)) == NULL) {
 	  
 #ifdef DEBUG
 		  dbg_write(debug_log, DBG_ERR, (Component *)NULL,
