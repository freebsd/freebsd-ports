--- guicontrol.c.orig	1997-08-23 11:30:51 UTC
+++ guicontrol.c
@@ -375,7 +375,8 @@ int decodeMPEG_2(int inFilefd)
 	break;	
       case GETHDR_SYN: warn("oops, we're out of sync.\n");
 	break;
-      default: 
+      default:
+	break;
       }
       break;
     }
