--- libgapvidapi/gap_vid_api_ffmpeg.c.orig	2007-08-22 09:59:27.000000000 -0400
+++ libgapvidapi/gap_vid_api_ffmpeg.c	2007-08-22 10:06:41.000000000 -0400
@@ -1721,7 +1721,7 @@
 		      );
 	      }
 #endif	      
-              rfps = ic->streams[ii]->r_frame_rate;
+              rfps = ic->streams[ii]->r_frame_rate.num;
               acc->workaround_bugs = FF_BUG_AUTODETECT;
               acc->error_resilience = 2;
               acc->error_concealment = 3;
@@ -1734,15 +1734,15 @@
               {
                   acc->flags|= CODEC_FLAG_TRUNCATED;
               }
-              if (acc->frame_rate != rfps)
+              if (acc->time_base.num != rfps)
               {
                   printf("\nSeems that stream %d comes from film source: %2.2f->%2.2f\n",
-                      ii, (float)acc->frame_rate / (float)acc->frame_rate_base,
-                      (float)rfps / (float)acc->frame_rate_base);
+                      ii, (float)acc->time_base.num / (float)acc->time_base.den,
+                      (float)rfps / (float)acc->time_base.den);
               }
 
               /* update the current frame rate to match the stream frame rate */
-              gvahand->framerate = (gdouble)rfps / (gdouble)acc->frame_rate_base;
+              gvahand->framerate = (gdouble)rfps / (gdouble)acc->time_base.den;
             }
             break;
         default:
