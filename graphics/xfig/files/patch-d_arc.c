--- d_arc.c.orig	Fri May  5 07:40:15 2006
+++ d_arc.c
@@ -308,7 +308,7 @@
     if (num_point == 0)
 	length_msg(MSG_RADIUS);
     else {
-	compute_3p_angle(&tpoint[0], &center_point, &p3, &alpha);
+	compute_3p_angle((F_point *)&tpoint[0], (F_point *)&center_point, &p3, &alpha);
 	put_msg("1st angle = %.2f degrees", (float) alpha*180.0/M_PI);
     }
     elastic_arc();
