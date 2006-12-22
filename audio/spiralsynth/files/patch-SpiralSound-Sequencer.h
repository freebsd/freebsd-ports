--- SpiralSound/Sequencer.h.orig	Fri Dec 22 18:51:59 2006
+++ SpiralSound/Sequencer.h	Fri Dec 22 18:52:21 2006
@@ -40,7 +40,7 @@
 	void SetLength(int s) {m_Length=s;}
 	void SetArp(bool s) {m_Arp=s;}
 	void SetArpNotes(int s) {m_ArpNotes=s;}
-	bool Sequencer::GetSeqNote(float &note, int &oct, int &key);
+	bool GetSeqNote(float &note, int &oct, int &key);
 
 private:
 
