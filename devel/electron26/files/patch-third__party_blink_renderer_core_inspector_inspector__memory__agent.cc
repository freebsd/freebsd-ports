--- third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2023-05-25 00:42:04 UTC
+++ third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -189,7 +189,7 @@ InspectorMemoryAgent::GetSamplingProfileById(uint32_t 
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const WebVector<void*>& addresses) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<void*> addresses_to_symbolize;
   for (size_t i = 0; i < addresses.size(); i++) {
