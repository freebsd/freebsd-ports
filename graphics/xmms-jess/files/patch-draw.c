
$FreeBSD$

--- draw.c.orig	Sun Aug 22 17:51:02 2004
+++ draw.c	Sun Aug 22 17:51:23 2004
@@ -510,7 +510,7 @@
 	  }
       }
     break;
-  default:
+  default: break;
   }
   /*  printf("  Appel rotation_3d\n");
   printf("  Appel perspective\n");
@@ -623,7 +623,7 @@
 	}
       break;
 
-    default:
+    default: break;
     }
 }
 
