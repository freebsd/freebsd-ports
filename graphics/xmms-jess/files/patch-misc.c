
$FreeBSD$

--- misc.c.orig	Sun Aug 22 17:51:48 2004
+++ misc.c	Sun Aug 22 17:52:27 2004
@@ -195,10 +195,10 @@
 	  printf("Color mode : %i\n",conteur.triplet);
 	  break;
 
-	default:
+	default: break;
 	}   
       break;
-    default:
+    default: break;
     }
 
 }
