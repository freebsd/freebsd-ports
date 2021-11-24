--- third_party/blink/renderer/core/inspector/inspector_memory_agent.cc.orig	2021-01-07 00:36:42 UTC
+++ third_party/blink/renderer/core/inspector/inspector_memory_agent.cc
@@ -186,7 +186,7 @@ InspectorMemoryAgent::GetSamplingProfileById(uint32_t 
 
 Vector<String> InspectorMemoryAgent::Symbolize(
     const WebVector<void*>& addresses) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(alph): Move symbolization to the client.
   Vector<void*> addresses_to_symbolize;
   for (size_t i = 0; i < addresses.size(); i++) {
