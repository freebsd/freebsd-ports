--- creox/effects_dsp/tremoloprocessor.cpp.orig	2011-06-21 21:27:40 UTC
+++ creox/effects_dsp/tremoloprocessor.cpp
@@ -182,8 +182,8 @@ void TremoloProcessor::signalFlow_run(co
 		register const float inputSample = *(inputBuffer++) * m_inputGain_f;
 #ifdef FP_FAST_FMAF
 		*(outputBuffer++) = (inputSample * m_dry_f)
-						  + (inputSample * m_wet_f * std::fmaf(amplitudeModulation,
-															   m_modulationMulti, m_modulationShift);
+						  + (inputSample * m_wet_f * fmaf(amplitudeModulation,
+															   m_modulationMulti, m_modulationShift));
 #else
 		*(outputBuffer++) = (inputSample * m_dry_f)
 						  + (inputSample * m_wet_f * ((amplitudeModulation * m_modulationMulti)
