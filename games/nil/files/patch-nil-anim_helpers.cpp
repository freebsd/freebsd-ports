--- nil/anim_helpers.cpp.orig	Sat Nov 15 16:43:08 2003
+++ nil/anim_helpers.cpp	Sat Nov 15 16:57:35 2003
@@ -210,7 +210,7 @@
 	}
 
 	if (hit != end())
-  	return hit;
+  	return &(*hit);
 	else {
 		logmsg(lt_debug,"Unable to find a suitable aim_id for elevation: %.2f (%i angles were tried)",elevation,size());
 		return NULL;
