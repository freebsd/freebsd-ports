--- cmt.cpp.orig       Wed Jun  5 23:15:32 2002
+++ cmt.cpp    Wed Jun  5 23:16:33 2002
@@ -115,9 +115,9 @@
 void CMT_Descriptor::
 addPort(LADSPA_PortDescriptor          iPortDescriptor,
       const char *                   pcPortName,
-      LADSPA_PortRangeHintDescriptor iHintDescriptor = 0,
-      LADSPA_Data                    fLowerBound = 0,
-      LADSPA_Data                    fUpperBound = 0) {
+      LADSPA_PortRangeHintDescriptor iHintDescriptor,
+      LADSPA_Data                    fLowerBound,
+      LADSPA_Data                    fUpperBound) {

   unsigned long lOldPortCount = PortCount;
   unsigned long lNewPortCount = PortCount + 1;
