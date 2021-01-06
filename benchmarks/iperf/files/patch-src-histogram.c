--- src/histogram.c.orig	2020-11-30 18:53:55 UTC
+++ src/histogram.c
@@ -239,11 +239,11 @@ void histogram_print(struct histogram *h, double start
       fprintf(stdout, "%s (%.2f/%.2f/99.7%%=%d/%d/%d,Outliers=%d,obl/obu=%d/%d)", \
 	      h->outbuf, h->ci_lower, h->ci_upper, lowerci, upperci, upper3stdev, outliercnt, oob_l, oob_u);
     if (!h->final && (h->maxval > 0)) {
-	fprintf(stdout, " (%0.3f ms/%ld.%ld)\n", (h->maxval * 1e3), h->maxts.tv_sec, (long) h->maxts.tv_usec);
+	fprintf(stdout, " (%0.3f ms/%ld.%ld)\n", (h->maxval * 1e3), (long) h->maxts.tv_sec, (long) h->maxts.tv_usec);
       h->maxbin = -1;
       h->maxval = 0;
     } else if (h->final && (h->fmaxval > 0)) {
-	fprintf(stdout, " (%0.3f ms/%ld.%ld)\n", (h->fmaxval * 1e3), h->fmaxts.tv_sec, (long) h->fmaxts.tv_usec);
+	fprintf(stdout, " (%0.3f ms/%ld.%ld)\n", (h->fmaxval * 1e3), (long) h->fmaxts.tv_sec, (long) h->fmaxts.tv_usec);
     } else {
       fprintf(stdout, "\n");
     }
