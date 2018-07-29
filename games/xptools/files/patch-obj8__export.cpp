--- src/AC3DPlugins/obj8_export.cpp.orig	2018-07-05 08:55:46 UTC
+++ src/AC3DPlugins/obj8_export.cpp
@@ -825,8 +825,8 @@ void ag_output_polygon(FILE * fi, Surfac
 
 		if (p1->y == p2->y &&
 			p1->y == p3->y &&	
-			p1->y == p4->y)
-		if(s->normal.y > 0.0)
+			p1->y == p4->y) {
+		if(s->normal.y > 0.0) {
 
 		if(p1->y < 0.0)
 		{
@@ -849,6 +849,8 @@ void ag_output_polygon(FILE * fi, Surfac
 				p3->x + x_off,z_off + p3->z,
 				p4->x + x_off,z_off + p4->z);		
 		}
+		}
+		}
 	}
 }
 
@@ -896,4 +898,4 @@ int do_ag_save(char * fname, ACObject * 
 	
 	fclose(fi);
 	return 1;
-}
\ No newline at end of file
+}
