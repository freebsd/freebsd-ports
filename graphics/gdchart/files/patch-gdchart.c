--- gdchart.c.orig	Mon Apr 19 00:37:46 1999
+++ gdchart.c	Mon Jun  4 02:40:16 2001
@@ -3,7 +3,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <values.h>
+#include <limits.h>
 #include <math.h>
 #include <string.h>
 #include <stdarg.h>
@@ -517,7 +517,7 @@
 
 	if( GDC_xaxis && xlbl )
 		{
-		int biggest     = -MAXINT;
+		int biggest     = -INT_MAX;
 
 		for( i=0; i<num_points; ++i )
 			{
@@ -727,7 +727,7 @@
 			}
 		else
 			{
-			if( bg_img = gdImageCreateFromGif(in) )					// =
+			if( bg_img = gdImageCreateFromPng(in) )					// =
 				{
 				int	bgxpos = gdImageSX(bg_img)<GIFWIDTH?  GIFWIDTH/2 - gdImageSX(bg_img)/2:  0,
 					bgypos = gdImageSY(bg_img)<GIFHEIGHT? GIFHEIGHT/2 - gdImageSY(bg_img)/2: 0;
@@ -1028,7 +1028,7 @@
 		int		num_xlbls =										/* maximum x lables that'll fit */
 																/* each xlbl + avg due to num_lf_xlbls */
 					graphwidth /
-						( (GDC_xlabel_spacing==MAXSHORT?0:GDC_xlabel_spacing)+GDC_fontc[GDC_xaxisfont_size].h +
+						( (GDC_xlabel_spacing==SHRT_MAX?0:GDC_xlabel_spacing)+GDC_fontc[GDC_xaxisfont_size].h +
 						  (num_lf_xlbls*(GDC_fontc[GDC_xaxisfont_size].h-1))/num_points );
 		int		labelcolor = GDC_XLabelColor==GDC_DFLTCOLOR? 
 							 LineColor: clrallocate( im, GDC_XLabelColor );
@@ -1036,7 +1036,7 @@
 		for( i=0; i<num_points+(do_bar?2:0); ++i )
 			if( (i%(1+num_points/num_xlbls) == 0) ||					// # x labels are regulated
 				(num_xlbls >= num_points)         ||
-				GDC_xlabel_spacing == MAXSHORT )
+				GDC_xlabel_spacing == SHRT_MAX )
 				{
 				int	xi = do_bar? i-1: i;
 
@@ -1817,7 +1817,7 @@
 	if( GDC_generate_gif )
 		{
 		fflush(gif_fptr);			// clear anything buffered 
-		gdImageGif( im, gif_fptr );
+		gdImagePng( im, gif_fptr );
 		}
 
 	if( bg_img )
