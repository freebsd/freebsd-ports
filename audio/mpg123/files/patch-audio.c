
$FreeBSD$

--- audio.c.orig	Tue Apr  6 18:53:05 1999
+++ audio.c	Tue Aug 21 19:38:08 2001
@@ -62,8 +62,45 @@
  AUDIO_FORMAT_ALAW_8
 };
 
+/* 0: not checked
+ * 1: capable
+ * -1: not capable
+ */
 static char capabilities[NUM_CHANNELS][NUM_ENCODINGS][NUM_RATES];
 
+/* true  (1): capable
+ * false (0): not capable
+ */
+static char get_capabilities(struct audio_info_struct *ai,
+                            int channel,int encoding,int rate) {
+    /* printf("get_capabilities(%d,%d,%d)\n",channel,encoding,rate); */
+    if (capabilities[channel][encoding][rate] == 0) {
+       struct audio_info_struct ai1 = *ai;
+       int fmts;
+       int k;
+       ai1.channels = channels[channel];
+       ai1.rate     = rates[rate];
+       fmts = audio_get_formats(&ai1);
+       /*printf("fmts=%x\n",fmts); */
+       fflush(stdout);
+       if (fmts < 0)
+           for (k=0; k<NUM_ENCODINGS; k++)
+               capabilities[channel][k][rate] = -1;
+       else
+           for (k=0; k<NUM_ENCODINGS; k++)
+               if ((fmts & encodings[k]) == encodings[k])
+                   capabilities[channel][k][rate] = 1;
+               else
+                   capabilities[channel][k][rate] = -1;
+    }
+    switch (capabilities[channel][encoding][rate]){
+    case 1: return 1;
+    case -1: return 0;
+    default:
+       abort();
+    }
+}
+
 void audio_capabilities(struct audio_info_struct *ai)
 {
 	int fmts;
@@ -86,6 +123,8 @@
 		exit(1);
 	}
 
+	/*
+
 	for(i=0;i<NUM_CHANNELS;i++) {
 		for(j=0;j<NUM_RATES;j++) {
 			ai1.channels = channels[i];
@@ -100,7 +139,7 @@
 		}
 	}
 
-	audio_close(&ai1);
+	*/
 
 	if(param.verbose > 1) {
 		fprintf(stderr,"\nAudio capabilities:\n        |");
@@ -111,13 +150,13 @@
 		for(k=0;k<k1;k++) {
 			fprintf(stderr," %5d  |",rates[k]);
 			for(j=0;j<NUM_ENCODINGS;j++) {
-				if(capabilities[0][j][k]) {
-					if(capabilities[1][j][k])
+				if(get_capabilities(&ai1,0,j,k)) {
+					if(get_capabilities(&ai1,1,j,k))
 						fprintf(stderr,"  M/S  |");
 					else
 						fprintf(stderr,"   M   |");
 				}
-				else if(capabilities[1][j][k])
+				else if(get_capabilities(&ai1,1,j,k))
 					fprintf(stderr,"   S   |");
 				else
 					fprintf(stderr,"       |");
@@ -126,6 +165,9 @@
 		}
 		fprintf(stderr,"\n");
 	}
+
+	audio_close(&ai1);
+
 }
 
 static int rate2num(int r)
@@ -144,7 +186,7 @@
 
         if(rn >= 0) {
                 for(i=f0;i<f2;i++) {
-                        if(capabilities[c][i][rn]) {
+                        if(get_capabilities(ai,c,i,rn)) {
                                 ai->rate = rates[rn];
                                 ai->format = encodings[i];
                                 ai->channels = channels[c];
