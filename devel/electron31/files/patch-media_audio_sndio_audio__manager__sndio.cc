--- media/audio/sndio/audio_manager_sndio.cc.orig	2024-06-30 11:49:01 UTC
+++ media/audio/sndio/audio_manager_sndio.cc
@@ -0,0 +1,241 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/command_line.h"
+#include "base/metrics/histogram_macros.h"
+#include "base/memory/ptr_util.h"
+
+#include "media/audio/sndio/audio_manager_sndio.h"
+
+#include "media/audio/audio_device_description.h"
+#include "media/audio/audio_output_dispatcher.h"
+#if defined(USE_SNDIO)
+#include "media/audio/sndio/sndio_input.h"
+#include "media/audio/sndio/sndio_output.h"
+#endif
+#if defined(USE_PULSEAUDIO)
+#include "media/audio/pulse/audio_manager_pulse.h"
+#include "media/audio/pulse/pulse_util.h"
+#endif
+#if defined(USE_ALSA)
+#include "media/audio/alsa/audio_manager_alsa.h"
+#endif
+#include "media/audio/fake_audio_manager.h"
+#include "media/base/limits.h"
+#include "media/base/media_switches.h"
+
+namespace media {
+
+#if defined(USE_SNDIO)
+// Maximum number of output streams that can be open simultaneously.
+static const int kMaxOutputStreams = 50;
+
+// Default sample rate for input and output streams.
+static const int kDefaultSampleRate = 48000;
+
+#if BUILDFLAG(IS_OPENBSD)
+static const std::string kDefaultAudioBackend = "sndio";
+#else
+static const std::string kDefaultAudioBackend = "auto";
+#endif
+
+void AddDefaultDevice(AudioDeviceNames* device_names) {
+  DCHECK(device_names->empty());
+  device_names->push_front(AudioDeviceName::CreateDefault());
+}
+
+bool AudioManagerSndio::HasAudioOutputDevices() {
+  return true;
+}
+
+bool AudioManagerSndio::HasAudioInputDevices() {
+  return true;
+}
+
+void AudioManagerSndio::GetAudioInputDeviceNames(
+    AudioDeviceNames* device_names) {
+  DCHECK(device_names->empty());
+  AddDefaultDevice(device_names);
+}
+
+void AudioManagerSndio::GetAudioOutputDeviceNames(
+    AudioDeviceNames* device_names) {
+  AddDefaultDevice(device_names);
+}
+
+#if defined(USE_SNDIO)
+const char* AudioManagerSndio::GetName() {
+  return "SNDIO";
+}
+#endif
+
+AudioParameters AudioManagerSndio::GetInputStreamParameters(
+    const std::string& device_id) {
+  static const int kDefaultInputBufferSize = 1024;
+
+  int user_buffer_size = GetUserBufferSize();
+  int buffer_size = user_buffer_size ?
+      user_buffer_size : kDefaultInputBufferSize;
+
+  return AudioParameters(
+      AudioParameters::AUDIO_PCM_LOW_LATENCY, ChannelLayoutConfig::Stereo(),
+      kDefaultSampleRate, buffer_size);
+}
+
+AudioManagerSndio::AudioManagerSndio(std::unique_ptr<AudioThread> audio_thread,
+                                         AudioLogFactory* audio_log_factory)
+    : AudioManagerBase(std::move(audio_thread),
+                       audio_log_factory) {
+  DLOG(WARNING) << "AudioManagerSndio";
+  SetMaxOutputStreamsAllowed(kMaxOutputStreams);
+}
+
+AudioManagerSndio::~AudioManagerSndio() = default;
+
+AudioOutputStream* AudioManagerSndio::MakeLinearOutputStream(
+    const AudioParameters& params,
+    const LogCallback& log_callback) {
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LINEAR, params.format());
+  return MakeOutputStream(params);
+}
+
+AudioOutputStream* AudioManagerSndio::MakeLowLatencyOutputStream(
+    const AudioParameters& params,
+    const std::string& device_id,
+    const LogCallback& log_callback) {
+  DLOG_IF(ERROR, !device_id.empty()) << "Not implemented!";
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LOW_LATENCY, params.format());
+  return MakeOutputStream(params);
+}
+
+AudioInputStream* AudioManagerSndio::MakeLinearInputStream(
+    const AudioParameters& params,
+    const std::string& device_id,
+    const LogCallback& log_callback) {
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LINEAR, params.format());
+  return MakeInputStream(params);
+}
+
+AudioInputStream* AudioManagerSndio::MakeLowLatencyInputStream(
+    const AudioParameters& params,
+    const std::string& device_id,
+    const LogCallback& log_callback) {
+  DCHECK_EQ(AudioParameters::AUDIO_PCM_LOW_LATENCY, params.format());
+  return MakeInputStream(params);
+}
+
+AudioParameters AudioManagerSndio::GetPreferredOutputStreamParameters(
+    const std::string& output_device_id,
+    const AudioParameters& input_params) {
+  // TODO(tommi): Support |output_device_id|.
+  DLOG_IF(ERROR, !output_device_id.empty()) << "Not implemented!";
+  static const int kDefaultOutputBufferSize = 2048;
+
+  ChannelLayoutConfig channel_layout_config = ChannelLayoutConfig::Stereo();
+  int sample_rate = kDefaultSampleRate;
+  int buffer_size = kDefaultOutputBufferSize;
+  if (input_params.IsValid()) {
+    sample_rate = input_params.sample_rate();
+    channel_layout_config = input_params.channel_layout_config();
+    buffer_size = std::min(buffer_size, input_params.frames_per_buffer());
+  }
+
+  int user_buffer_size = GetUserBufferSize();
+  if (user_buffer_size)
+    buffer_size = user_buffer_size;
+
+  return AudioParameters(
+      AudioParameters::AUDIO_PCM_LOW_LATENCY,
+      channel_layout_config, sample_rate, buffer_size);
+}
+
+AudioInputStream* AudioManagerSndio::MakeInputStream(
+    const AudioParameters& params) {
+  DLOG(WARNING) << "MakeInputStream";
+  return new SndioAudioInputStream(this,
+             AudioDeviceDescription::kDefaultDeviceId, params);
+}
+
+AudioOutputStream* AudioManagerSndio::MakeOutputStream(
+    const AudioParameters& params) {
+  DLOG(WARNING) << "MakeOutputStream";
+  return new SndioAudioOutputStream(params, this);
+}
+#endif
+
+std::unique_ptr<media::AudioManager> CreateAudioManager(
+    std::unique_ptr<AudioThread> audio_thread,
+    AudioLogFactory* audio_log_factory) {
+  DLOG(WARNING) << "CreateAudioManager";
+  std::string audio_backend = kDefaultAudioBackend;
+
+  std::vector<std::string> kSupportedAudioBackends = {"auto"};
+
+#if defined(USE_SNDIO)
+  kSupportedAudioBackends.push_back(std::string("sndio"));
+#endif
+#if defined(USE_PULSEAUDIO)
+  kSupportedAudioBackends.push_back(std::string("pulse"));
+#endif
+#if defined(USE_ALSA)
+  kSupportedAudioBackends.push_back(std::string("alsa"));
+#endif
+
+  if (base::CommandLine::ForCurrentProcess()->HasSwitch(
+          switches::kAudioBackend)) {
+    audio_backend = base::CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
+        switches::kAudioBackend);
+  }
+
+  // For testing allow audio output to be disabled.
+  if (base::CommandLine::ForCurrentProcess()->HasSwitch(
+          switches::kDisableAudioOutput)) {
+    return std::make_unique<FakeAudioManager>(std::move(audio_thread),
+                                              audio_log_factory);
+  }
+
+  if (std::find(std::begin(kSupportedAudioBackends), std::end(kSupportedAudioBackends),
+      audio_backend) == std::end(kSupportedAudioBackends)) {
+    LOG(ERROR) << "Unsupported audio backend specified. Falling back to " << kDefaultAudioBackend;
+    audio_backend = kDefaultAudioBackend;
+  }
+
+#if defined(USE_PULSEAUDIO)
+  pa_threaded_mainloop* pa_mainloop = nullptr;
+  pa_context* pa_context = nullptr;
+  if ((audio_backend != "sndio" && audio_backend != "alsa") &&
+      pulse::InitPulse(&pa_mainloop, &pa_context)) {
+    return std::make_unique<AudioManagerPulse>(
+        std::move(audio_thread), audio_log_factory, pa_mainloop, pa_context);
+  } else if (audio_backend == "auto") {
+    LOG(WARNING) << "Falling back to SNDIO for audio output. PulseAudio is not "
+                    "available or could not be initialized.";
+  }
+#endif
+
+#if defined(USE_SNDIO)
+  if (audio_backend != "pulse" && audio_backend != "alsa") {
+    return std::make_unique<AudioManagerSndio>(std::move(audio_thread),
+                                              audio_log_factory);
+  } else if (audio_backend == "auto") {
+    LOG(WARNING) << "Falling back to ALSA audio output. SNDIO is not "
+                    "available or could not be initialized.";
+  }
+#endif
+
+#if defined(USE_ALSA)
+  if (audio_backend != "pulse" && audio_backend != "sndio") {
+    return std::make_unique<AudioManagerAlsa>(std::move(audio_thread),
+                                              audio_log_factory);
+  } else if (audio_backend == "auto") {
+    LOG(WARNING) << "Falling back to fake audio output. ALSA is not "
+                    "available or could not be initialized.";
+  }
+#endif
+
+  return std::make_unique<FakeAudioManager>(std::move(audio_thread),
+                                            audio_log_factory);
+}
+
+}  // namespace media
