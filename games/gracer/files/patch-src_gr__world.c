--- src/gr_world.c.orig	2000-03-01 04:28:24 UTC
+++ src/gr_world.c
@@ -167,8 +167,6 @@ gr_world_check_trigger (GrWorld *world, int side)
     case GR_CLINE_B_TO_A:
       vehicle->lap_count --;
       break;
-
-    default:
     }
 
     tlist = entry->triggers;
