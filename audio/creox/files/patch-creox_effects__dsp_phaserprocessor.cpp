--- creox/effects_dsp/phaserprocessor.cpp.orig	2011-06-21 21:27:40 UTC
+++ creox/effects_dsp/phaserprocessor.cpp
@@ -157,7 +157,8 @@ void PhaserProcessor::signalFlow_run(con
 			{
 				const float omega = 2.0f * float(M_PI) * m_stepFrequency / m_samplerate_d;
 				float sn, cs;
-				sincosf(omega, &sn, &cs);
+				sn = sinf(omega);
+				cs = cosf(omega);
 				*(m_coefBuffPrelim++) = cs; // cs
 				*(m_coefBuffPrelim++) = sn / m_resonance; // alpha (m_resonance = 2.0*resonance)
 				m_stepFrequency *= m_expStep;
@@ -232,7 +233,8 @@ void PhaserProcessor::signalFlow_run(con
 			}
 
 			float sn, cs;
-			sincosf(omega, &sn, &cs);
+			sn = sinf(omega);
+			cs = cosf(omega);
 			register const float alpha = sn / m_resonance; // alpha (m_resonance = 2.0 * resonance)
 
 			// perform filter
