--- app/tracer.c.orig	Sat Feb 25 21:30:54 2006
+++ app/tracer.c	Sun Feb 26 13:14:18 2006
@@ -361,15 +361,19 @@
 void 
 tracer_trace (int mixfreq, int songpos, int patpos)
 {
+    st_mixer *real_mixer;
+    int stopsongpos, stoppatpos;
+    double rest, previous;
+
     /* Attemp to take pitchband into account */
     /* Test if tempo and BPM are traced */
-    st_mixer *real_mixer = mixer;
+    real_mixer = mixer;
     mixer = &mixer_tracer;
 
-    int stopsongpos = songpos;
-    int stoppatpos = patpos;
+    stopsongpos = songpos;
+    stoppatpos = patpos;
 
-    double rest = 0, previous = 0; /* Fractional part of the samples */
+    rest = 0, previous = 0; /* Fractional part of the samples */
     
     if((stoppatpos -= 1) < 0){
 	stopsongpos -= 1;
@@ -381,12 +385,13 @@
 
     while(1) {
 	double t;
+	guint32 samples;
 	
 	double current = xmplayer_play();
 	t = current - previous + rest;
 	previous = current;
 	
-	guint32 samples = t * mixfreq;
+	samples = t * mixfreq;
 	rest = t - (double)samples / (double)mixfreq;
 	
 	tracer_mix(NULL, samples, NULL, 0);
