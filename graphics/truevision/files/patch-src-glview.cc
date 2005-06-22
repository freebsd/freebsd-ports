--- src/glview.cc.orig	Sun Jun 12 02:34:25 2005
+++ src/glview.cc	Tue Jun 21 01:06:43 2005
@@ -676,15 +676,15 @@
 		default:
 			break;
 		case TV_VIEW_TOP:
-			tmp_coord += fmax(fabs(lookat->get(0)), fabs(lookat->get(2)));
+			tmp_coord += ((fabs(lookat->get(0)))>(fabs(lookat->get(2)))?(fabs(lookat->get(0))):(fabs(lookat->get(2))));
 			break;
 			
 		case TV_VIEW_FRONT:
-			tmp_coord += fmax(fabs(lookat->get(0)), fabs(lookat->get(1)));
+			tmp_coord += ((fabs(lookat->get(0)))>(fabs(lookat->get(1)))?(fabs(lookat->get(0))):(fabs(lookat->get(1))));
 			break;
 			
 		case TV_VIEW_RIGHT:
-			tmp_coord += fmax(fabs(lookat->get(1)), fabs(lookat->get(2)));
+			tmp_coord += ((fabs(lookat->get(1)))>(fabs(lookat->get(2)))?(fabs(lookat->get(1))):(fabs(lookat->get(2))));
 			break;
 		}
 
