--- src/cpp/piper.cpp.orig
+++ src/cpp/piper.cpp
@@ -6,7 +6,7 @@
 #include <stdexcept>
 
 #include <espeak-ng/speak_lib.h>
-#include <onnxruntime_cxx_api.h>
+#include <onnxruntime/onnxruntime_cxx_api.h>
 #include <spdlog/spdlog.h>
 
 #include "json.hpp"
@@ -229,22 +229,6 @@ void initialize(PiperConfig &config) {
     spdlog::debug("Initialized eSpeak");
   }
 
-  // Load onnx model for libtashkeel
-  // https://github.com/mush42/libtashkeel/
-  if (config.useTashkeel) {
-    spdlog::debug("Using libtashkeel for diacritization");
-    if (!config.tashkeelModelPath) {
-      throw std::runtime_error("No path to libtashkeel model");
-    }
-
-    spdlog::debug("Loading libtashkeel model from {}",
-                  config.tashkeelModelPath.value());
-    config.tashkeelState = std::make_unique<tashkeel::State>();
-    tashkeel::tashkeel_load(config.tashkeelModelPath.value(),
-                            *config.tashkeelState);
-    spdlog::debug("Initialized libtashkeel");
-  }
-
   spdlog::info("Initialized piper");
 }
 
@@ -447,15 +431,6 @@ void textToAudio(PiperConfig &config, Voice &voice, std::string text,
         voice.synthesisConfig.sampleRate * voice.synthesisConfig.channels);
   }
 
-  if (config.useTashkeel) {
-    if (!config.tashkeelState) {
-      throw std::runtime_error("Tashkeel model is not loaded");
-    }
-
-    spdlog::debug("Diacritizing text with libtashkeel: {}", text);
-    text = tashkeel::tashkeel_run(text, *config.tashkeelState);
-  }
-
   // Phonemes for each sentence
   spdlog::debug("Phonemizing text: {}", text);
   std::vector<std::vector<Phoneme>> phonemes;
--- src/cpp/piper.hpp.orig
+++ src/cpp/piper.hpp
@@ -8,7 +8,7 @@
 #include <string>
 #include <vector>
 
-#include <onnxruntime_cxx_api.h>
+#include <onnxruntime/onnxruntime_cxx_api.h>
 #include <piper-phonemize/phoneme_ids.hpp>
 #include <piper-phonemize/phonemize.hpp>
 #include <piper-phonemize/tashkeel.hpp>
