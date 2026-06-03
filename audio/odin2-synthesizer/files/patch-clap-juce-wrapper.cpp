-- Add JUCE_BSD to ensure compatibility with FreeBSD.

--- libs/clap-juce-extensions/src/wrapper/clap-juce-wrapper.cpp.orig	2026-05-17 03:55:19 UTC
+++ libs/clap-juce-extensions/src/wrapper/clap-juce-wrapper.cpp
@@ -35,7 +35,7 @@ JUCE_END_IGNORE_WARNINGS_GCC_LIKE
 
 #include <clap-juce-extensions/clap-juce-extensions.h>
 
-#if JUCE_LINUX
+#if JUCE_LINUX || JUCE_BSD
 #include <juce_audio_plugin_client/utility/juce_LinuxMessageThread.h>
 #endif
 
@@ -159,7 +159,7 @@ class ClapJuceWrapper : public clap::helpers::Plugin<c
     {
         processor->editorBeingDeleted(editor.get());
 
-#if JUCE_LINUX
+#if JUCE_LINUX || JUCE_BSD
         if (_host.canUseTimerSupport())
         {
             _host.timerSupportUnregister(idleTimer);
@@ -169,7 +169,7 @@ class ClapJuceWrapper : public clap::helpers::Plugin<c
 
     bool init() noexcept override
     {
-#if JUCE_LINUX
+#if JUCE_LINUX || JUCE_BSD
         if (_host.canUseTimerSupport())
         {
             _host.timerSupportRegister(1000 / 50, &idleTimer);
@@ -969,7 +969,7 @@ class ClapJuceWrapper : public clap::helpers::Plugin<c
     }
 #endif
 
-#if JUCE_LINUX
+#if JUCE_LINUX || JUCE_BSD
     bool guiX11Attach(const char *displayName, unsigned long window) noexcept
     {
         const juce::MessageManagerLock mmLock;
@@ -1093,7 +1093,7 @@ extern "C"
 
 extern "C"
 {
-#if JUCE_LINUX
+#if JUCE_LINUX || JUCE_BSD
 #pragma GCC diagnostic ignored "-Wattributes"
 #endif
     const CLAP_EXPORT struct clap_plugin_entry clap_entry = {CLAP_VERSION, ClapAdapter::clap_init,
