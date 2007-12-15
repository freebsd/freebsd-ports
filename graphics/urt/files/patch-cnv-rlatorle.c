--- cnv/rlatorle.c.orig	Thu Nov 29 22:14:43 2007
+++ cnv/rlatorle.c	Thu Nov 29 22:15:43 2007
@@ -162,7 +162,7 @@
        }
    VPRINTF(stderr, "Channel color space %s\n", head.rla_head.chan);
    if ( rlb_flag )
-       VPRINTF(stderr, "Interlaced?         %s\n", head.rlb_head.filter_type);
+       VPRINTF(stderr, "Interlaced?         %hd\n", head.rlb_head.filter_type);
    else
        VPRINTF(stderr, "Interlaced?         %s\n", "-unused-");
    if (do_matte)
