--- src/gr_world.c.orig	Wed May  4 18:49:13 2005
+++ src/gr_world.c	Wed May  4 18:49:24 2005
@@ -167,8 +167,6 @@
     case GR_CLINE_B_TO_A:
       vehicle->lap_count --;
       break;
-
-    default:
     }
 
     tlist = entry->triggers;
