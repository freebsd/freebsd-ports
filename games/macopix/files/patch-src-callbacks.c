--- src/callbacks.c.orig	2008-05-25 07:40:08.000000000 +0200
+++ src/callbacks.c	2013-09-13 17:00:08.911683055 +0200
@@ -509,7 +509,7 @@
 		if((win_bar_size==0)&&(mascot->no_capbar)){
 		  // for windows w/o title bar 
 		  flag_homepos=mascot->homepos_nb;
-		  if(flag_homepos==HOMEPOS_NEVER) return;
+		  if(flag_homepos==HOMEPOS_NEVER) return(0);
 		}
 	      }
 	      //win_bar_size=0;
@@ -538,7 +538,7 @@
 	    if((win_bar_size==0)&&(mascot->no_capbar)){
 	      // for windows w/o title bar 
 	      flag_homepos=mascot->homepos_nb;
-	      if(flag_homepos==HOMEPOS_NEVER) return;
+	      if(flag_homepos==HOMEPOS_NEVER) return(0);
 	    }
 	    break;
 	  }
