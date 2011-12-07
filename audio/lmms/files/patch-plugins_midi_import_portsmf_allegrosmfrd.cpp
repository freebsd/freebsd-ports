--- plugins/midi_import/portsmf/allegrosmfrd.cpp	2011-07-02 13:14:01.000000000 +0000
+++ plugins/midi_import/portsmf/allegrosmfrd.cpp.new	2011-09-30 21:07:19.000000000 +0000
@@ -327,7 +327,7 @@
 
 void Alg_midifile_reader::Mf_arbitrary(int len, char *msg)
 {
-    Mf_error("arbitrary data ignored");
+    Mf_error((char *)"arbitrary data ignored");
 }
 
 
@@ -341,11 +341,11 @@
 
 void Alg_midifile_reader::Mf_seqnum(int n)
 {
-    Mf_error("seqnum data ignored");
+    Mf_error((char *)"seqnum data ignored");
 }
 
 
-static char *fpsstr[4] = {"24", "25", "29.97", "30"};
+static char *fpsstr[4] = {(char *)"24", (char *)"25", (char *)"29.97", (char *)"30"};
 
 void Alg_midifile_reader::Mf_smpte(int hours, int mins, int secs,
                                    int frames, int subframes)
