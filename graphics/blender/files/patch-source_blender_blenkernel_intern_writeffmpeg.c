--- source/blender/blenkernel/intern/writeffmpeg.c.orig	2009-06-01 17:26:43.000000000 +0200
+++ source/blender/blenkernel/intern/writeffmpeg.c	2009-06-01 17:27:38.000000000 +0200
@@ -519,7 +519,7 @@
 
 	/* xasp & yasp got float lately... */
 
-	st->sample_aspect_ratio = c->sample_aspect_ratio = av_d2q(
+	st->codec->sample_aspect_ratio = c->sample_aspect_ratio = av_d2q(
 		((double) G.scene->r.xasp / (double) G.scene->r.yasp), 255);
 
 	set_ffmpeg_properties(c, "video");
