--- ladspa_sdk/src/plugins/sine.cpp.orig       2002-07-06 17:23:17.000000000 
0000
+++ src/plugins/sine.cpp    2005-11-25 11:15:11.691087784 +0000
@@ -59,6 +59,15 @@
 
 /*****************************************************************************/
 
+LADSPA_Handle instantiateSineOscillator(const LADSPA_Descriptor *, unsigned long SampleRate);
+void connectPortToSineOscillator(LADSPA_Handle Instance, unsigned long Port, LADSPA_Data * DataLocation);
+void activateSineOscillator(void * pvHandle);
+void runSineOscillator_FreqAudio_AmpAudio(LADSPA_Handle Instance, unsigned long SampleCount);
+void runSineOscillator_FreqAudio_AmpCtrl(LADSPA_Handle Instance, unsigned long SampleCount);
+void runSineOscillator_FreqCtrl_AmpAudio(LADSPA_Handle Instance, unsigned long SampleCount);
+void runSineOscillator_FreqCtrl_AmpCtrl(LADSPA_Handle Instance, unsigned long SampleCount);
+void cleanupSineOscillator(void *pvHandle);
+
 class SineOscillator {
 private:
