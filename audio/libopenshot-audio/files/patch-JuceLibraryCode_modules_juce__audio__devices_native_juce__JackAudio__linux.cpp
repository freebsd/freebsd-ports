--- JuceLibraryCode/modules/juce_audio_devices/native/juce_JackAudio_linux.cpp.orig	2024-12-21 22:21:33 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/native/juce_JackAudio_linux.cpp
@@ -182,6 +182,8 @@ class JackAudioIODevice final : public AudioIODevice (
         {
             juce::jack_set_error_function (errorCallback);
 
+            if (inputId.isNotEmpty())
+            {
             // open input ports
             const StringArray inputChannels (getInputChannelNames());
             for (int i = 0; i < inputChannels.size(); ++i)
@@ -192,7 +194,10 @@ class JackAudioIODevice final : public AudioIODevice (
                 inputPorts.add (juce::jack_port_register (client, inputChannelName.toUTF8(),
                                                           JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0));
             }
+            }
 
+            if (outputId.isNotEmpty())
+            {
             // open output ports
             const StringArray outputChannels (getOutputChannelNames());
             for (int i = 0; i < outputChannels.size(); ++i)
@@ -202,6 +207,7 @@ class JackAudioIODevice final : public AudioIODevice (
 
                 outputPorts.add (juce::jack_port_register (client, outputChannelName.toUTF8(),
                                                            JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0));
+            }
             }
 
             inChans.calloc (totalNumberOfInputChannels + 2);
