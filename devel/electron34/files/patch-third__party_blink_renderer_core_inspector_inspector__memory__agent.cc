--- third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2024-02-21 00:20:53 UTC
+++ third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -192,7 +192,7 @@ Vector<String> InspectorMemoryAgent::Symbolize(
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const WebVector<const void*>& addresses) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<const void*> addresses_to_symbolize;
   for (const void* address : addresses) {
