--- src/callbcks.c.orig	Mon Dec  6 23:40:28 2004
+++ src/callbcks.c	Mon Dec  6 23:40:51 2004
@@ -90,7 +90,6 @@
     case ROT_LEFT90:
       viewer_data->rotation = ROT_RIGHT90;
       break;
-    default:
     }
   
   draw_page (viewer_data);
@@ -113,7 +112,6 @@
     case ROT_LEFT90:
       viewer_data->rotation = ROT_NONE;
       break;
-    default:
     }
 
   draw_page (viewer_data);
@@ -136,7 +134,6 @@
     case ROT_LEFT90:
       viewer_data->rotation = ROT_180;
       break;
-    default:
     }
   
   draw_page (viewer_data);
