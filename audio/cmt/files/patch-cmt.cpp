--- cmt.cpp.orig	Sat Jul 13 20:59:44 2002
+++ cmt.cpp	Sat Jul 13 21:00:21 2002
@@ -115,9 +115,9 @@
 void CMT_Descriptor::
 addPort(LADSPA_PortDescriptor          iPortDescriptor,
 	const char *                   pcPortName,
-	LADSPA_PortRangeHintDescriptor iHintDescriptor = 0,
-	LADSPA_Data                    fLowerBound = 0,
-	LADSPA_Data                    fUpperBound = 0) {
+	LADSPA_PortRangeHintDescriptor iHintDescriptor,
+	LADSPA_Data                    fLowerBound,
+	LADSPA_Data                    fUpperBound) {
 
   unsigned long lOldPortCount = PortCount;
   unsigned long lNewPortCount = PortCount + 1;
