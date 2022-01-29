--- audio/drivers/mididriver.cpp.orig	2022-01-29 16:09:37 UTC
+++ audio/drivers/mididriver.cpp
@@ -112,8 +112,14 @@ static const unsigned int outCap = SND_SEQ_PORT_CAP_SU
 //---------------------------------------------------------
 
 AlsaMidiDriver::AlsaMidiDriver(Seq* s)
-   : MidiDriver(s)
+    : MidiDriver(s), alsaSeq(0)
       {
+      }
+
+AlsaMidiDriver::~AlsaMidiDriver()
+      {
+      if (alsaSeq)
+            snd_seq_close(alsaSeq);
       }
 
 //---------------------------------------------------------
