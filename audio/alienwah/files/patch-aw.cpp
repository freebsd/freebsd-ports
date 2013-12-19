--- aw.cpp.orig	2002-01-26 02:51:03.000000000 +0900
+++ aw.cpp	2013-12-04 04:50:18.000000000 +0900
@@ -62,11 +62,11 @@
 
 /*****************************************************************************/
 
-#include <math.h>
-#include <complex.h>
-#include <stdlib.h>
-#include <string.h>
-#include <stdio.h>
+#include <cmath>
+#include <complex>
+#include <cstdlib>
+#include <cstring>
+#include <cstdio>
 
 /*****************************************************************************/
 
@@ -85,6 +85,8 @@
 #define AW_INPUT2     6
 #define AW_OUTPUT2    7
 
+#define AW_NUMPORTS   8
+
 /*****************************************************************************/
 /* Make number of samples represented by 'delay' proportional to
  * the sample rate, such that delay=1 is 1 sample buffer at
@@ -118,10 +120,10 @@
 unsigned long t2;              //??
 unsigned long k;               // index for delaybuf
 unsigned long k2;              // index for delaybuf2
-float_complex * delaybuf;
-float_complex * delaybuf2;
-float_complex c;               //??
-float_complex c2;              //??
+std::complex<float> * delaybuf;
+std::complex<float> * delaybuf2;
+std::complex<float> c;               //??
+std::complex<float> c2;              //??
 float freq;
 float startphase;
 float feedback;
@@ -135,25 +137,61 @@
 	samplerate(lSampleRate),
 	t(0), t2(0),
 	k(0), k2(0),
-	c(float_complex(0,0)),
-	c2(float_complex(0,0)) {
+	c(std::complex<float>(0,0)),
+	c2(std::complex<float>(0,0)) {
 }
 
+friend LADSPA_Handle instantiateAW(const LADSPA_Descriptor *,
+				   unsigned long SampleRate);
+friend void connectPortToAW(LADSPA_Handle instance, unsigned long port,
+			    LADSPA_Data * datalocation);
+friend void activateAW(void * pvHandle);
+friend void runAW_Mono(LADSPA_Handle instance, unsigned long samplecount);
+friend void runAW_Stereo(LADSPA_Handle instance, unsigned long samplecount);
+friend void cleanupAW(void *pvHandle);
+
 /*
- * simply calls the constructor
+ * Munge some things based upon the settings passed. Set
+ * initial state.
  */
-friend LADSPA_Handle instantiateAW(const LADSPA_Descriptor *,
-	unsigned long SampleRate) {
+void initState(int chans) {
+	inited = true;
+	freq = (float)lfreq;
+	feedback = ((float)lfeedback)/4 + 0.74; // whyfor?
+	if (feedback>0.999) feedback=0.999;
+	if (ldelay < 0) ldelay = 1;
+	// swh I think this is wrong delay = (unsigned int) (ldelay * samplerate * NORM);
+	delay = (unsigned int) ldelay;
+printf("delay %d\n", delay);
+	if (delay < 1) delay = 1;
+	if (delay > MAX_DELAY) delay = MAX_DELAY;
+	delaybuf = new std::complex<float>[delay];
+	if (chans == 2) {
+		delaybuf2 = new std::complex<float>[MAX_DELAY+1];
+	}
+	for (unsigned int i =0; i<delay; ++i) {
+		delaybuf[i] = std::complex<float>(0,0);
+	}
+}
 
+};
+
+
+/*
+ * simply calls the constructor
+ */
+LADSPA_Handle instantiateAW(const LADSPA_Descriptor *,
+			    unsigned long SampleRate)
+{
   return new AW(SampleRate);
 }
 
 /*
  * get all the pointers to our ports data 
  */
-friend void connectPortToAW(LADSPA_Handle instance, unsigned long port,
-	LADSPA_Data * datalocation) {
-
+void connectPortToAW(LADSPA_Handle instance, unsigned long port,
+		     LADSPA_Data * datalocation)
+{
 	switch (port) {
 	case AW_FREQ:
 		((AW *)instance)->lfreq = *datalocation;
@@ -182,41 +220,19 @@
  * connect_port may be called before of after here, so we
  * cannot rely upon port data for initialization
  */
-friend void activateAW(void * pvHandle) {
-}
-
-/*
- * Munge some things based upon the settings passed. Set
- * initial state.
- */
-void initState(int chans) {
-	inited = true;
-	freq = (float)lfreq;
-	feedback = ((float)lfeedback)/4 + 0.74; // whyfor?
-	if (feedback>0.999) feedback=0.999;
-	if (ldelay < 0) ldelay = 1;
-	// swh I think this is wrong delay = (unsigned int) (ldelay * samplerate * NORM);
-	delay = (unsigned int) ldelay;
-printf("delay %d\n", delay);
-	if (delay < 1) delay = 1;
-	if (delay > MAX_DELAY) delay = MAX_DELAY;
-	delaybuf = new float_complex[delay];
-	if (chans == 2) {
-		delaybuf2 = new float_complex[MAX_DELAY+1];
-	}
-	for (unsigned int i =0; i<delay; ++i) {
-		delaybuf[i] = float_complex(0,0);
-	}
+void activateAW(void * pvHandle)
+{
 }
 
 /*
  * Mono effect
  * Do the effect. 'i_buf' is transformed into 'o_buf'
  */
-friend void runAW_Mono(LADSPA_Handle instance, unsigned long samplecount) {
+void runAW_Mono(LADSPA_Handle instance, unsigned long samplecount)
+{
 	AW * me = (AW *)instance;
 	float lfo;
-	float_complex outc;
+	std::complex<float> outc;
 	float lfoskip = me->freq * 2 * PI / me->samplerate;
 
 	if (! me->inited) me->initState(1);
@@ -224,7 +240,7 @@
 	for(unsigned int i=0; i<samplecount; ++i) {
 		if ((me->t++ % LFO_SKIPSAMPLES) == 0) {
 			lfo = 1 + cos(me->t * lfoskip + me->startphase);
-			me->c = float_complex(cos(lfo) * me->feedback,
+			me->c = std::complex<float>(cos(lfo) * me->feedback,
 				 sin(lfo) * me->feedback);
 		}
 		outc = me->c * me->delaybuf[me->k] + (1 - me->feedback) * 
@@ -238,10 +254,11 @@
 /*
  * Stereo effect?
  */
-friend void runAW_Stereo(LADSPA_Handle instance, unsigned long samplecount) {
+void runAW_Stereo(LADSPA_Handle instance, unsigned long samplecount)
+{
 	AW * me = (AW *)instance;
 	float lfo;
-	float_complex outc;
+	std::complex<float> outc;
 	float lfoskip = me->freq * 2 * PI / me->samplerate;
 
 	if (! me->inited) me->initState(2);
@@ -249,7 +266,7 @@
 	for(unsigned int i=0; i<samplecount; ++i) {
 		if ((me->t++ % LFO_SKIPSAMPLES) == 0) {
 			lfo = 1 + cos(me->t * lfoskip + me->startphase);
-			me->c = float_complex(cos(lfo) * me->feedback,
+			me->c = std::complex<float>(cos(lfo) * me->feedback,
 				 sin(lfo) * me->feedback);
 		}
 		outc = me->c * me->delaybuf[me->k] + (1 - me->feedback) * 
@@ -262,7 +279,7 @@
 	for(unsigned int i=0; i<samplecount; ++i) {
 		if ((me->t2++ % LFO_SKIPSAMPLES) == 0) {
 			lfo = 1 + cos(me->t2 * lfoskip);
-			me->c2 = float_complex(cos(lfo) * me->feedback,
+			me->c2 = std::complex<float>(cos(lfo) * me->feedback,
 				 sin(lfo) * me->feedback);
 		}
 		outc = me->c2 * me->delaybuf2[me->k2] + (1 - me->feedback) * 
@@ -273,13 +290,11 @@
 	}
 }
 
-
-friend void cleanupAW(void *pvHandle) {
-  delete (AW *)pvHandle;
+void cleanupAW(void *pvHandle)
+{
+	delete (AW *)pvHandle;
 }
 
-};
-
 /*****************************************************************************/
 
 typedef char * char_ptr;
@@ -342,7 +357,7 @@
     desc[plug]->PortCount 
 	= 6;
     portdesc
-	= new LADSPA_PortDescriptor[6];
+	= new LADSPA_PortDescriptor[AW_NUMPORTS];
     desc[plug]->PortDescriptors 
 	= (const LADSPA_PortDescriptor *)portdesc;
     portdesc[AW_FREQ]
@@ -358,7 +373,7 @@
     portdesc[AW_OUTPUT1]
 	= LADSPA_PORT_OUTPUT | LADSPA_PORT_AUDIO;
     pnames
-	= new char_ptr[6];
+	= new char_ptr[AW_NUMPORTS];
     desc[plug]->PortNames
 	= (const char **)pnames;
     pnames[AW_FREQ]
@@ -376,7 +391,7 @@
 
 /* range hints */
     rangehints 
-	= new LADSPA_PortRangeHint[6];
+	= new LADSPA_PortRangeHint[AW_NUMPORTS];
     desc[plug]->PortRangeHints
 	= (const LADSPA_PortRangeHint *)rangehints;
 
@@ -417,7 +432,7 @@
     desc[plug]->PortCount 
 	= 8;
     portdesc
-	= new LADSPA_PortDescriptor[8];
+	= new LADSPA_PortDescriptor[AW_NUMPORTS];
     desc[plug]->PortDescriptors 
 	= (const LADSPA_PortDescriptor *)portdesc;
     portdesc[AW_FREQ]
@@ -437,7 +452,7 @@
     portdesc[AW_OUTPUT1]
 	= LADSPA_PORT_OUTPUT | LADSPA_PORT_AUDIO;
     pnames
-	= new char_ptr[8];
+	= new char_ptr[AW_NUMPORTS];
     desc[plug]->PortNames
 	= (const char **)pnames;
     pnames[AW_FREQ]
@@ -459,7 +474,7 @@
 
 /* range hints */
     rangehints 
-	= new LADSPA_PortRangeHint[8];
+	= new LADSPA_PortRangeHint[AW_NUMPORTS];
     desc[plug]->PortRangeHints
 	= (const LADSPA_PortRangeHint *)rangehints;
 
