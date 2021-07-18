--- source/modules/AppConfig.h.orig	2021-03-21 01:16:46 UTC
+++ source/modules/AppConfig.h
@@ -29,13 +29,15 @@
 # define APPCONFIG_OS_MAC
 #elif defined(__linux__) || defined(__linux)
 # define APPCONFIG_OS_LINUX
+#elif defined(__FreeBSD__)
+# define APPCONFIG_OS_FREEBSD
 #else
 # error Unsupported platform!
 #endif
 
 #if defined(APPCONFIG_OS_WIN32) || defined(APPCONFIG_OS_WIN64)
 # define APPCONFIG_OS_WIN
-#elif defined(APPCONFIG_OS_LINUX) || defined(APPCONFIG_OS_MAC)
+#elif defined(APPCONFIG_OS_LINUX) || defined(APPCONFIG_OS_FREEBSD) || defined(APPCONFIG_OS_MAC)
 # define APPCONFIG_OS_UNIX
 #endif
 
@@ -81,7 +83,7 @@
 #define JUCE_STRING_UTF_TYPE 8
 #define JUCE_USE_VFORK 1
 
-#ifdef APPCONFIG_OS_LINUX
+#if defined(APPCONFIG_OS_LINUX) || defined(APPCONFIG_OS_FREEBSD)
 # define JUCE_DISABLE_NATIVE_FILECHOOSERS 1
 # define JUCE_MODAL_LOOPS_PERMITTED 0
 // # define JUCE_AUDIOPROCESSOR_NO_GUI 1
@@ -145,7 +147,7 @@
 /** Config: JUCE_JACK
     Enables JACK audio devices (Linux only).
 */
-#ifdef APPCONFIG_OS_LINUX
+#if defined(APPCONFIG_OS_LINUX) || defined(APPCONFIG_OS_FREEBSD)
  #define JUCE_JACK 1
  #define JUCE_JACK_CLIENT_NAME "Carla"
 #else
@@ -227,7 +229,7 @@
 
     @see VSTPluginFormat, VST3PluginFormat, AudioPluginFormat, AudioPluginFormatManager, JUCE_PLUGINHOST_VST, JUCE_PLUGINHOST_AU
 */
-#if defined(APPCONFIG_OS_LINUX) || defined(APPCONFIG_OS_MAC) || defined(APPCONFIG_OS_WIN)
+#if defined(APPCONFIG_OS_LINUX) || defined(APPCONFIG_OS_FREEBSD) || defined(APPCONFIG_OS_MAC) || defined(APPCONFIG_OS_WIN)
 # define JUCE_PLUGINHOST_VST3 1
 #else
 # define JUCE_PLUGINHOST_VST3 0
