--- src/librt/g_bot_include.c.orig	Thu Feb 10 22:36:31 2005
+++ src/librt/g_bot_include.c	Thu Feb 10 22:38:50 2005
@@ -280,7 +280,7 @@
 		VMOVE( p2, &bot_ip->vertices[bot_ip->faces[tri_index*3 + 1]*3] );
 		VMOVE( p3, &bot_ip->vertices[bot_ip->faces[tri_index*3 + 2]*3] );
 
-		if( rt_bot_minpieces <= 0 || bot_ip->num_faces < rt_bot_minpieces ) {
+		if( rt_bot_minpieces <= 0 || bot_ip->num_faces <= rt_bot_minpieces ) {
 			VMINMAX( stp->st_min, stp->st_max, p1 );
 			VMINMAX( stp->st_min, stp->st_max, p2 );
 			VMINMAX( stp->st_min, stp->st_max, p3 );
