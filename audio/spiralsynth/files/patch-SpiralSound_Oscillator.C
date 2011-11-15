--- SpiralSound/Oscillator.C.orig	2011-11-15 14:22:27.000000000 +0100
+++ SpiralSound/Oscillator.C	2011-11-15 14:22:21.000000000 +0100
@@ -30,7 +30,10 @@
 m_PulseWidth(0.5f),
 m_PortmentoSpeed(1),
 m_DesiredFreq(0),
-m_ModAmount(0.01f)
+m_ModAmount(0.01f),
+m_FreqModBuf(0),
+m_PulseWidthModBuf(0),
+m_SHModBuf(0)
 {
 	m_CyclePos=new int[SpiralInfo::POLY];
 	m_InOctave=new int[SpiralInfo::POLY];
