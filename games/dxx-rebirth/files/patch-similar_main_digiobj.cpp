--- similar/main/digiobj.cpp.orig	2019-05-27 11:05:14 UTC
+++ similar/main/digiobj.cpp
@@ -578,7 +578,7 @@ void digi_sync_sounds()
                                 &s.volume, &s.pan, s.max_distance );
 
 			} else if ( s.flags & SOF_LINK_TO_OBJ )	{
-				const auto objp = [&vcobjptr, &s]{
+				const auto objp = [&s]{
 					if (Newdemo_state != ND_STATE_PLAYBACK)
 						return vcobjptr(s.link_type.obj.objnum);
 					auto objnum = newdemo_find_object(s.link_type.obj.objsignature);
