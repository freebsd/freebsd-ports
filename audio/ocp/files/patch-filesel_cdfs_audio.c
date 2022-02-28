--- filesel/cdfs/audio.c.orig	2022-02-28 13:08:06 UTC
+++ filesel/cdfs/audio.c
@@ -131,9 +131,8 @@ void __attribute__ ((visibility ("internal"))) Check_A
 		}
 failout:
 		discid_free (did);
-postfailout:
 	}
-
+postfailout:
 	AudioDir = CDFS_Directory_add (disc, 0, "AUDIO");
 
 	{
