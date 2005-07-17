--- src/dataformat.c.orig	Wed Jul 13 07:44:46 2005
+++ src/dataformat.c	Wed Jul 13 22:33:54 2005
@@ -353,10 +353,10 @@
 	  memcpy(outdata,indata,count*indata_format->samplesize);
      } else if (indata_format->type == DATAFORMAT_PCM) {
 	  if (outdata_format->type == DATAFORMAT_PCM) {
+	       char *c;
 	       /* PCM -> PCM conversion */
 	       if (outdata_format->samplesize > indata_format->samplesize)
 		    dither_mode = DITHER_NONE;
-	       char *c;
 	       c = g_malloc(count * sizeof(sample_t));	       
 	       convert_array(indata,indata_format,c,&dataformat_sample_t,
 			     count,dither_mode);
