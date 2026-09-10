--- third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2026-06-23 23:37:18 UTC
+++ third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -198,7 +198,7 @@ Vector<String> InspectorMemoryAgent::Symbolize(
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const std::vector<const void*>& addresses) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<const void*> addresses_to_symbolize;
   for (const void* address : addresses) {
