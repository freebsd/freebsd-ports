--- creox/effects_dsp/echoprocessor.cpp.orig	2011-06-21 21:27:40 UTC
+++ creox/effects_dsp/echoprocessor.cpp
@@ -221,7 +221,7 @@ void EchoProcessor::signalFlow_run(const
 			parallelEchoes += parEcho * m_parallelEchoParam[count].decay_f;
 #ifdef FP_FAST_FMAF
 			*(m_parallelEchoChain[count].buffer + m_parallelEchoChain[count].offset) =
-								std::fmaf(parEcho, m_parallelEchoParam[count].feedback_f, inputSample);
+								fmaf(parEcho, m_parallelEchoParam[count].feedback_f, inputSample);
 #else
 			*(m_parallelEchoChain[count].buffer + m_parallelEchoChain[count].offset) =
 									inputSample + (parEcho * m_parallelEchoParam[count].feedback_f);
