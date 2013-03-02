--- creox/effects_dsp/echoprocessor.cpp.orig	2011-06-22 06:27:40.000000000 +0900
+++ creox/effects_dsp/echoprocessor.cpp	2013-02-18 21:05:56.000000000 +0900
@@ -221,7 +221,7 @@
 			parallelEchoes += parEcho * m_parallelEchoParam[count].decay_f;
 #ifdef FP_FAST_FMAF
 			*(m_parallelEchoChain[count].buffer + m_parallelEchoChain[count].offset) =
-								std::fmaf(parEcho, m_parallelEchoParam[count].feedback_f, inputSample);
+								fmaf(parEcho, m_parallelEchoParam[count].feedback_f, inputSample);
 #else
 			*(m_parallelEchoChain[count].buffer + m_parallelEchoChain[count].offset) =
 									inputSample + (parEcho * m_parallelEchoParam[count].feedback_f);
