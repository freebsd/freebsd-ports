--- gdchart.c.orig	Sat Nov  4 02:49:46 2000
+++ gdchart.c	Mon Jun 18 00:56:42 2001
@@ -664,7 +664,7 @@
 
 	if( GDC_xaxis && xlbl )
 		{
-		int biggest     = -MAXINT;
+		int biggest     = -INT_MAX;
 
 		for( i=0; i<num_points; ++i )
 			{
@@ -1196,7 +1196,7 @@
 		int		num_xlbls =										/* maximum x lables that'll fit */
 																/* each xlbl + avg due to num_lf_xlbls */
 					graphwidth /
-						( (GDC_xlabel_spacing==MAXSHORT?0:GDC_xlabel_spacing)+GDC_fontc[GDC_xaxisfont_size].h +
+						( (GDC_xlabel_spacing==SHRT_MAX?0:GDC_xlabel_spacing)+GDC_fontc[GDC_xaxisfont_size].h +
 						  (num_lf_xlbls*(GDC_fontc[GDC_xaxisfont_size].h-1))/num_points );
 		int		labelcolor = GDC_XLabelColor==GDC_DFLTCOLOR? 
 							 LineColor: clrallocate( im, GDC_XLabelColor );
@@ -1226,7 +1226,7 @@
 			/* labeled points */
 			if( (!GDC_xlabel_ctl && ( (i%(1+num_points/num_xlbls) == 0) ||	// # x labels are regulated
 										  num_xlbls >= num_points       ||
-										  GDC_xlabel_spacing == MAXSHORT ))
+										  GDC_xlabel_spacing == SHRT_MAX ))
 				||
 				(GDC_xlabel_ctl && xi>=0 && *(GDC_xlabel_ctl+xi)) )
 				{
