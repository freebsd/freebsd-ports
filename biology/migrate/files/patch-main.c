--- main.c.orig	2010-01-20 23:47:41.000000000 +0900
+++ main.c	2010-02-01 23:02:52.000000000 +0900
@@ -630,7 +630,9 @@
 	      {
 		fprintf(EARTH->outfile,"%5li %10.5f\n",locus+1,universe[locus]->averageheat);
 	      }
+#ifdef PRETTY
 	    pdf_print_averageheat(universe,options);
+#endif
 	  }
 #ifdef PRETTY
 	pdf_print_end_time(&page_height);
@@ -2443,8 +2445,10 @@
     {
       fprintf(file,"\n\nLocus      Raw Thermodynamic score(1a)  Bezier approximated score(1b)     Harmonic mean(2)\n");
       fprintf(file,"------------------------------------------------------------------------------------------\n");
+#ifdef PRETTY
       if(file==EARTH->outfile)
 	pdf_bayes_factor_rawscores_header(EARTH,options);
+#endif
     }
   if(options->heating)//-----------------------heating
     {
