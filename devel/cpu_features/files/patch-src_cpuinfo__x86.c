--- src/cpuinfo_x86.c.orig	2020-10-15 09:09:51 UTC
+++ src/cpuinfo_x86.c
@@ -97,7 +97,8 @@
 // microarchitectures.
 #if defined(CPU_FEATURES_OS_WINDOWS)
 #include <windows.h>  // IsProcessorFeaturePresent
-#elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID)
+#elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID) || \
+    defined(CPU_FEATURES_OS_FREEBSD)
 #include "internal/filesystem.h"         // Needed to parse /proc/cpuinfo
 #include "internal/stack_line_reader.h"  // Needed to parse /proc/cpuinfo
 #include "internal/string_view.h"        // Needed to parse /proc/cpuinfo
@@ -1239,6 +1240,45 @@ static void DetectSseViaOs(X86Features* features) {
   features->ssse3 = GetDarwinSysCtlByName("hw.optional.supplementalsse3");
   features->sse4_1 = GetDarwinSysCtlByName("hw.optional.sse4_1");
   features->sse4_2 = GetDarwinSysCtlByName("hw.optional.sse4_2");
+#elif defined(CPU_FEATURES_OS_FREEBSD)
+    // Handling FreeBSD platform through parsing /var/run/dmesg.boot.
+    const int fd = CpuFeatures_OpenFile("/var/run/dmesg.boot");
+    if (fd >= 0) {
+      StackLineReader reader;
+      StackLineReader_Initialize(&reader, fd);
+      for (;;) {
+        const LineResult result = StackLineReader_NextLine(&reader);
+        const StringView line = result.line;
+        const bool is_feature =
+            CpuFeatures_StringView_StartsWith(line, str("  Features="));
+        const bool is_feature2 =
+            CpuFeatures_StringView_StartsWith(line, str("  Features2="));
+        if (is_feature || is_feature2) {
+          // Lines of interests are of the following form:
+          // "  Features=0x1783fbff<PSE36,MMX,FXSR,SSE,SSE2,HTT>"
+          // We replace '<', '>' and ',' with space so we can search by
+          // whitespace separated word.
+          // TODO: Fix CpuFeatures_StringView_HasWord to allow for different
+          // separators.
+          for (size_t i = 0; i < line.size; ++i) {
+            char* c = (char*)(&(line.ptr[i]));
+            if (*c == '<' || *c == '>' || *c == ',') *c = ' ';
+          }
+          if (is_feature) {
+            features->sse = CpuFeatures_StringView_HasWord(line, "SSE");
+            features->sse2 = CpuFeatures_StringView_HasWord(line, "SSE2");
+          }
+          if (is_feature2) {
+            features->sse3 = CpuFeatures_StringView_HasWord(line, "SSE3");
+            features->ssse3 = CpuFeatures_StringView_HasWord(line, "SSSE3");
+            features->sse4_1 = CpuFeatures_StringView_HasWord(line, "SSE4.1");
+            features->sse4_2 = CpuFeatures_StringView_HasWord(line, "SSE4.2");
+          }
+        }
+        if (result.eof) break;
+      }
+      CpuFeatures_CloseFile(fd);
+    }
 #elif defined(CPU_FEATURES_OS_LINUX_OR_ANDROID)
   // Handling Linux platform through /proc/cpuinfo.
   const int fd = CpuFeatures_OpenFile("/proc/cpuinfo");
@@ -1525,6 +1565,8 @@ X86Microarchitecture GetX86Microarchitecture(const X86
         return AMD_JAGUAR;
       case 0x17:
         return AMD_ZEN;
+      case 0x19:
+        return AMD_ZEN3;
       default:
         return X86_UNKNOWN;
     }
@@ -1617,6 +1659,8 @@ const char* GetX86MicroarchitectureName(X86Microarchit
       return "AMD_JAGUAR";
     case AMD_ZEN:
       return "AMD_ZEN";
+    case AMD_ZEN3:
+      return "AMD_ZEN3";
   }
   return "unknown microarchitecture";
 }
