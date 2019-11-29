--- playogg/oggplay.c.orig	2019-11-26 21:41:03 UTC
+++ playogg/oggplay.c
@@ -136,7 +136,7 @@ static void oggIdler(void)
 		}
 		if (ov_pcm_tell(&ov)!=oggpos)
 		{
-			fprintf (stderr, "[playogg]: warning, frame position is broken in file (got=%" __PRI64_PREFIX "d, expected= %" __PRI64_PREFIX "d)\n", ov_pcm_tell(&ov), oggpos);
+			fprintf (stderr, "[playogg]: warning, frame position is broken in file (got=%\" __PRI64_PREFIX \"d, expected= %\" __PRI64_PREFIX \"d)\n", ov_pcm_tell(&ov), oggpos);
 		}
 
 		ringbuffer_get_head_samples (oggbufpos, &pos1, &length1, &pos2, &length2);
