--- modules/juce_dsp/containers/juce_AudioBlock_test.cpp.orig	2023-08-23 16:47:58 UTC
+++ modules/juce_dsp/containers/juce_AudioBlock_test.cpp
@@ -28,8 +28,10 @@ namespace juce
 namespace dsp
 {
 
+#if JUCE_USE_SIMD
 template <typename SampleType>
 String& operator<< (String& str, SIMDRegister<SampleType>) { return str; }
+#endif
 
 template <typename SampleType>
 class AudioBlockUnitTests   : public UnitTest
