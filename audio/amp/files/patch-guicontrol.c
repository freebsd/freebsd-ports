--- guicontrol.c.orig	Fri Aug  6 17:54:38 2004
+++ guicontrol.c	Fri Aug  6 17:55:44 2004
@@ -375,7 +375,8 @@
 	break;	
       case GETHDR_SYN: warn("oops, we're out of sync.\n");
 	break;
-      default: 
+      default:
+	break;
       }
       break;
     }
