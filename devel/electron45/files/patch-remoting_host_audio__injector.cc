--- remoting/host/audio_injector.cc.orig	2026-06-23 23:37:18 UTC
+++ remoting/host/audio_injector.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #include "remoting/base/fifo_buffer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/pipewire_audio_injector.h"
 #endif
 
@@ -19,7 +19,7 @@ bool AudioInjector::IsSupported() {
 
 // static
 bool AudioInjector::IsSupported() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, we check if PipeWire is available and can be initialized.
   // Note that in multi-process mode, this may return true in the network
   // process because the libraries are loadable, even though the virtual audio
@@ -34,7 +34,7 @@ std::unique_ptr<AudioInjector> AudioInjector::Create(
 // static
 std::unique_ptr<AudioInjector> AudioInjector::Create(
     std::unique_ptr<FifoBufferReader> audio_reader) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return PipewireAudioInjector::Create(std::move(audio_reader));
 #else
   return nullptr;
