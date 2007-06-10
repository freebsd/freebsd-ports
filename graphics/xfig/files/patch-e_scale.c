--- e_scale.c.orig	Tue Jul 26 09:39:59 2005
+++ e_scale.c
@@ -460,7 +460,7 @@
     oldd = sqrt(oldx * oldx + oldy * oldy);
     scalefact = newd / oldd;
     /* scale any arrowheads */
-    scale_arrows(new_a,scalefact,scalefact);
+    scale_arrows((F_line *)new_a,scalefact,scalefact);
 
     relocate_arcpoint(new_a, x, y);
     change_arc(cur_a, new_a);
@@ -567,7 +567,7 @@
     set_action_object(F_EDIT, O_SPLINE);
     old_s->next = cur_s;
     /* now change the original to become the new object */
-    rescale_points(cur_s, x, y);
+    rescale_points((F_line *)cur_s, x, y);
     wrapup_scale();
     /* redraw anything under the old spline */
     redisplay_spline(old_s);
@@ -1048,7 +1048,7 @@
 	p->y = round(refy + (p->y - refy) * sy);
     }
     /* scale any arrowheads */
-    scale_arrows(s,sx,sy);
+    scale_arrows((F_line *)s,sx,sy);
 }
 
 static void
@@ -1090,7 +1090,7 @@
     }
     a->direction = compute_direction(a->point[0], a->point[1], a->point[2]);
     /* scale any arrowheads */
-    scale_arrows(a,sx,sy);
+    scale_arrows((F_line *)a,sx,sy);
 }
 
 static void
