--- include/raytrace.h.orig	Fri Mar 11 00:20:44 2005
+++ include/raytrace.h	Fri Mar 11 00:21:55 2005
@@ -5001,7 +5001,7 @@
 		    (struct bu_list		*vhead,
 		     const struct faceuse	*fu,
 		     int			poly_markers));
-RT_EXPORT BU_EXTERN(voidnmg_s_to_vlist,
+RT_EXPORT BU_EXTERN(void nmg_s_to_vlist,
 		    (struct bu_list		*vhead,
 		     const struct shell	*s,
 		     int			poly_markers));
