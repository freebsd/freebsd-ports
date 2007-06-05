--- aw.cpp.orig	Sat Jan 26 02:51:03 2002
+++ aw.cpp	Sat May 26 22:33:51 2007
@@ -85,6 +85,8 @@
 #define AW_INPUT2     6
 #define AW_OUTPUT2    7
 
+#define AW_NUMPORTS   8
+
 /*****************************************************************************/
 /* Make number of samples represented by 'delay' proportional to
  * the sample rate, such that delay=1 is 1 sample buffer at
@@ -139,21 +141,57 @@
 	c2(float_complex(0,0)) {
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
+	delaybuf = new float_complex[delay];
+	if (chans == 2) {
+		delaybuf2 = new float_complex[MAX_DELAY+1];
+	}
+	for (unsigned int i =0; i<delay; ++i) {
+		delaybuf[i] = float_complex(0,0);
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
@@ -182,38 +220,16 @@
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
 	float_complex outc;
@@ -238,7 +254,8 @@
 /*
  * Stereo effect?
  */
-friend void runAW_Stereo(LADSPA_Handle instance, unsigned long samplecount) {
+void runAW_Stereo(LADSPA_Handle instance, unsigned long samplecount)
+{
 	AW * me = (AW *)instance;
 	float lfo;
 	float_complex outc;
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
 
