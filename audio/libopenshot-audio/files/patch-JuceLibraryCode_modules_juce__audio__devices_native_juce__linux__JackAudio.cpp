--- JuceLibraryCode/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp.orig	2023-04-17 13:00:42 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/native/juce_linux_JackAudio.cpp
@@ -175,6 +175,8 @@ class JackAudioIODevice   : public AudioIODevice (publ
         {
             juce::jack_set_error_function (errorCallback);
 
+            if (inputId.isNotEmpty())
+            {
             // open input ports
             const StringArray inputChannels (getInputChannelNames());
             for (int i = 0; i < inputChannels.size(); ++i)
@@ -185,7 +187,10 @@ class JackAudioIODevice   : public AudioIODevice (publ
                 inputPorts.add (juce::jack_port_register (client, inputName.toUTF8(),
                                                           JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0));
             }
+            }
 
+            if (outputId.isNotEmpty())
+            {
             // open output ports
             const StringArray outputChannels (getOutputChannelNames());
             for (int i = 0; i < outputChannels.size(); ++i)
@@ -196,6 +201,7 @@ class JackAudioIODevice   : public AudioIODevice (publ
                 outputPorts.add (juce::jack_port_register (client, outputName.toUTF8(),
                                                            JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0));
             }
+            }
 
             inChans.calloc (totalNumberOfInputChannels + 2);
             outChans.calloc (totalNumberOfOutputChannels + 2);
@@ -273,26 +279,40 @@ class JackAudioIODevice   : public AudioIODevice (publ
 
         if (! inputChannels.isZero())
         {
-            for (JackPortIterator i (client, true); i.next();)
+            int idx = 0;
+            for (JackPortIterator i (client, true); i.next() && idx < inputPorts.size();)
             {
-                if (inputChannels [i.index] && i.clientName == getName())
+                if (i.clientName != getName())
+                    continue;
+                if (inputChannels [idx])
                 {
-                    int error = juce::jack_connect (client, i.ports[i.index], juce::jack_port_name ((jack_port_t*) inputPorts[i.index]));
+                    int error = juce::jack_connect (client, i.ports[i.index], juce::jack_port_name ((jack_port_t*) inputPorts[idx]));
                     if (error != 0)
+                    {
                         JUCE_JACK_LOG ("Cannot connect input port " + String (i.index) + " (" + i.name + "), error " + String (error));
+                    }
+                    else
+                        ++idx;
                 }
             }
         }
 
         if (! outputChannels.isZero())
         {
-            for (JackPortIterator i (client, false); i.next();)
+            int idx = 0;
+            for (JackPortIterator i (client, false); i.next() && idx < outputPorts.size();)
             {
-                if (outputChannels [i.index] && i.clientName == getName())
+                if (i.clientName != getName())
+                    continue;
+                if (outputChannels [idx])
                 {
-                    int error = juce::jack_connect (client, juce::jack_port_name ((jack_port_t*) outputPorts[i.index]), i.ports[i.index]);
+                    int error = juce::jack_connect (client, juce::jack_port_name ((jack_port_t*) outputPorts[idx]), i.ports[i.index]);
                     if (error != 0)
+                    {
                         JUCE_JACK_LOG ("Cannot connect output port " + String (i.index) + " (" + i.name + "), error " + String (error));
+                    }
+                    else
+                        ++idx;
                 }
             }
         }
@@ -536,20 +556,20 @@ class JackAudioIODeviceType  : public AudioIODeviceTyp
             // scan for output devices
             for (JackPortIterator i (client, false); i.next();)
             {
-                if (i.clientName != (JUCE_JACK_CLIENT_NAME) && ! inputNames.contains (i.clientName))
+                if (i.clientName != (JUCE_JACK_CLIENT_NAME) && ! outputNames.contains (i.clientName))
                 {
-                    inputNames.add (i.clientName);
-                    inputIds.add (i.ports [i.index]);
+                    outputNames.add (i.clientName);
+                    outputIds.add (i.ports [i.index]);
                 }
             }
 
             // scan for input devices
             for (JackPortIterator i (client, true); i.next();)
             {
-                if (i.clientName != (JUCE_JACK_CLIENT_NAME) && ! outputNames.contains (i.clientName))
+                if (i.clientName != (JUCE_JACK_CLIENT_NAME) && ! inputNames.contains (i.clientName))
                 {
-                    outputNames.add (i.clientName);
-                    outputIds.add (i.ports [i.index]);
+                    inputNames.add (i.clientName);
+                    inputIds.add (i.ports [i.index]);
                 }
             }
 
