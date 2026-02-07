# This patch fixes a bug where the tek2plot program misinterprets
# optimized Tek4014 datastreams which update LoY without sending
# the ExtraByte also.
# This patch has been submitted FSF:
# From:    "Poul-Henning Kamp" <phk@phk.freebsd.dk>
# Subject: Re: Bug in plotutils-2.5.1::tek2plot 
# To:      bug-gnu-utils@gnu.org
# Message-Id: <15929.1226142709@critter.freebsd.dk>
# Date:    Sat, 08 Nov 2008 11:11:49 GMT
#######################################################################

--- tek2plot/tek2plot.c.orig	2009-07-30 04:29:14 UTC
+++ tek2plot/tek2plot.c
@@ -559,7 +559,7 @@ getpoint (int *xcoor, int *ycoor, FILE *in_stream, int
   int temp_three = 0;
 
   /* following variables are saved from point to point */
-  static int saved_lo_y = 0, saved_hi_x = 0, saved_hi_y = 0;
+  static int saved_lo_y = 0, saved_hi_x = 0, saved_hi_y = 0, saved_egm = 0;
   static bool margin_reset = false;
 
   int byte_read, type;
@@ -709,10 +709,12 @@ getpoint (int *xcoor, int *ycoor, FILE *in_stream, int
 	    lo_y = got_lo_y ? lo_y : saved_lo_y;	      
 	    hi_x = got_hi_x ? hi_x : saved_hi_x;
 	    hi_y = got_hi_y ? hi_y : saved_hi_y;
+	    egm = got_egm ? egm : saved_egm;
 	    
 	    saved_lo_y = lo_y;
 	    saved_hi_x = hi_x;
 	    saved_hi_y = hi_y;	      
+	    saved_egm = egm;	      
 	    
 	    /* On a genuine Tektronix 4014, the MSB of the 5-bit EGM
 	       byte sets the margin to equal Margin2 (2048) */
