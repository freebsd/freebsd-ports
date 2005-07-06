
$FreeBSD$

--- oggenc/encode.c.orig
+++ oggenc/encode.c
@@ -160,6 +160,7 @@
         /* do we have optional hard bitrate restrictions? */
         if(opt->max_bitrate > 0 || opt->min_bitrate > 0){
             struct ovectl_ratemanage2_arg ai;
+            long bitrate;
 	        vorbis_encode_ctl(&vi, OV_ECTL_RATEMANAGE2_GET, &ai);
 
             /* libvorbis 1.1 (and current svn) doesn't actually fill this in,
@@ -173,7 +174,6 @@
                Also, note that this won't work correctly unless you have a very
                recent (2005/03/04 or later) version of libvorbis from svn).
              */
-            long bitrate;
 
             {
                 vorbis_info vi2;
