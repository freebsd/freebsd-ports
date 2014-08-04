--- modules/stimuli.cc.orig
+++ modules/stimuli.cc
@@ -216,7 +216,7 @@
   //----------------------------------------------------------------------
   //----------------------------------------------------------------------
 
-  PulseGen::PulseGen(const char *_name=0)
+  PulseGen::PulseGen(const char *_name)
     : StimulusBase(_name, "\
 Pulse Generator\n\
  Attributes:\n\
@@ -402,13 +402,20 @@
     setBreak(m_start_cycle + (*si).time, si);
 
   }
+
+  static bool compare_data_point(const ValueStimulusData &data_point1,
+                                 const ValueStimulusData &data_point2)
+  {
+    return (data_point1.time < data_point2.time);
+  }
+
   void PulseGen::put_data(ValueStimulusData &data_point)
   {
     list<ValueStimulusData>::iterator si;
     si = find(samples.begin(), samples.end(), data_point);
     if (si == samples.end()) {
       samples.push_back(data_point);
-      samples.sort();
+      samples.sort(compare_data_point);
     } else {
       delete (*si).v;
       (*si).v = data_point.v;
