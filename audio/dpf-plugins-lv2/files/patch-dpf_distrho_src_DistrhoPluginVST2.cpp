- patch from https://github.com/DISTRHO/DPF/commit/56c106c0fd886a5d29e018807f40adb00f57fe4e
- fixing build on FreeBSD 15 due to VST plugin issues

--- dpf/distrho/src/DistrhoPluginVST2.cpp.orig	2023-04-15 12:38:30 UTC
+++ dpf/distrho/src/DistrhoPluginVST2.cpp
@@ -1603,11 +1603,7 @@ DISTRHO_PLUGIN_EXPORT
 END_NAMESPACE_DISTRHO
 
 DISTRHO_PLUGIN_EXPORT
-#if defined(DISTRHO_OS_MAC) || defined(DISTRHO_OS_WASM) || defined(DISTRHO_OS_WINDOWS)
-const vst_effect* VSTPluginMain(vst_host_callback audioMaster);
-#else
-const vst_effect* VSTPluginMain(vst_host_callback audioMaster) asm ("main");
-#endif
+const vst_effect* VSTPluginMain(vst_host_callback);
 
 DISTRHO_PLUGIN_EXPORT
 const vst_effect* VSTPluginMain(const vst_host_callback audioMaster)
@@ -1731,4 +1727,14 @@ const vst_effect* VSTPluginMain(const vst_host_callbac
     return effect;
 }
 
-// -----------------------------------------------------------------------
+
+#if !(defined(DISTRHO_OS_MAC) || defined(DISTRHO_OS_WASM) || defined(DISTRHO_OS_WINDOWS))
+DISTRHO_PLUGIN_EXPORT
+const vst_effect* VSTPluginMainCompat(vst_host_callback) asm ("main");
+
+DISTRHO_PLUGIN_EXPORT
+const vst_effect* VSTPluginMainCompat(const vst_host_callback audioMaster)
+{
+    return VSTPluginMain(audioMaster);
+}
+#endif
