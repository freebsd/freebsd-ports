--- src/VBox/Devices/PC/vbox-cpuhotplug.dsl.orig	2019-10-10 18:34:15 UTC
+++ src/VBox/Devices/PC/vbox-cpuhotplug.dsl
@@ -44,11 +44,11 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", "SSDT", 1, "VB
     Scope (\_SB)
     {
 
-#define GENERATE_CPU_OBJECT(id, sck, sckuid, cpu, cpuuid)<NL>              \
+#define GENERATE_CPU_OBJECT(id, sck, cpu)<NL>                              \
     Device (sck)                                                           \
     {                                                                      \
         Name (_HID, "ACPI0004")                                            \
-        Name (_UID, sckuid)                                                \
+        Name (_UID, id)                                                    \
                                                                            \
         <NL>                                                               \
         Processor (cpu, /* Name */                                         \
@@ -58,7 +58,7 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", "SSDT", 1, "VB
                    )                                                       \
         {                                                                  \
             Name (_HID, "ACPI0007")                                        \
-            Name (_UID, cpuuid)                                            \
+            Name (_UID, id)                                                \
             Name (_PXM, 0x00)                                              \
             <NL>                                                           \
             Method(_MAT, 0, Serialized)                                    \
@@ -95,38 +95,38 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", "SSDT", 1, "VB
         }                                                                  \
     }                                                                      \
 
-        GENERATE_CPU_OBJECT(0x00, SCK0, "SCKCPU0", CPU0, "SCK0-CPU0")
-        GENERATE_CPU_OBJECT(0x01, SCK1, "SCKCPU1", CPU1, "SCK1-CPU0")
-        GENERATE_CPU_OBJECT(0x02, SCK2, "SCKCPU2", CPU2, "SCK2-CPU0")
-        GENERATE_CPU_OBJECT(0x03, SCK3, "SCKCPU3", CPU3, "SCK3-CPU0")
-        GENERATE_CPU_OBJECT(0x04, SCK4, "SCKCPU4", CPU4, "SCK4-CPU0")
-        GENERATE_CPU_OBJECT(0x05, SCK5, "SCKCPU5", CPU5, "SCK5-CPU0")
-        GENERATE_CPU_OBJECT(0x06, SCK6, "SCKCPU6", CPU6, "SCK6-CPU0")
-        GENERATE_CPU_OBJECT(0x07, SCK7, "SCKCPU7", CPU7, "SCK7-CPU0")
-        GENERATE_CPU_OBJECT(0x08, SCK8, "SCKCPU8", CPU8, "SCK8-CPU0")
-        GENERATE_CPU_OBJECT(0x09, SCK9, "SCKCPU9", CPU9, "SCK9-CPU0")
-        GENERATE_CPU_OBJECT(0x0a, SCKA, "SCKCPUA", CPUA, "SCKA-CPU0")
-        GENERATE_CPU_OBJECT(0x0b, SCKB, "SCKCPUB", CPUB, "SCKB-CPU0")
-        GENERATE_CPU_OBJECT(0x0c, SCKC, "SCKCPUC", CPUC, "SCKC-CPU0")
-        GENERATE_CPU_OBJECT(0x0d, SCKD, "SCKCPUD", CPUD, "SCKD-CPU0")
-        GENERATE_CPU_OBJECT(0x0e, SCKE, "SCKCPUE", CPUE, "SCKE-CPU0")
-        GENERATE_CPU_OBJECT(0x0f, SCKF, "SCKCPUF", CPUF, "SCKF-CPU0")
-        GENERATE_CPU_OBJECT(0x10, SCKG, "SCKCPUG", CPUG, "SCKG-CPU0")
-        GENERATE_CPU_OBJECT(0x11, SCKH, "SCKCPUH", CPUH, "SCKH-CPU0")
-        GENERATE_CPU_OBJECT(0x12, SCKI, "SCKCPUI", CPUI, "SCKI-CPU0")
-        GENERATE_CPU_OBJECT(0x13, SCKJ, "SCKCPUJ", CPUJ, "SCKJ-CPU0")
-        GENERATE_CPU_OBJECT(0x14, SCKK, "SCKCPUK", CPUK, "SCKK-CPU0")
-        GENERATE_CPU_OBJECT(0x15, SCKL, "SCKCPUL", CPUL, "SCKL-CPU0")
-        GENERATE_CPU_OBJECT(0x16, SCKM, "SCKCPUM", CPUM, "SCKM-CPU0")
-        GENERATE_CPU_OBJECT(0x17, SCKN, "SCKCPUN", CPUN, "SCKN-CPU0")
-        GENERATE_CPU_OBJECT(0x18, SCKO, "SCKCPUO", CPUO, "SCKO-CPU0")
-        GENERATE_CPU_OBJECT(0x19, SCKP, "SCKCPUP", CPUP, "SCKP-CPU0")
-        GENERATE_CPU_OBJECT(0x1a, SCKQ, "SCKCPUQ", CPUQ, "SCKQ-CPU0")
-        GENERATE_CPU_OBJECT(0x1b, SCKR, "SCKCPUR", CPUR, "SCKR-CPU0")
-        GENERATE_CPU_OBJECT(0x1c, SCKS, "SCKCPUS", CPUS, "SCKS-CPU0")
-        GENERATE_CPU_OBJECT(0x1d, SCKT, "SCKCPUT", CPUT, "SCKT-CPU0")
-        GENERATE_CPU_OBJECT(0x1e, SCKU, "SCKCPUU", CPUU, "SCKU-CPU0")
-        GENERATE_CPU_OBJECT(0x1f, SCKV, "SCKCPUV", CPUV, "SCKV-CPU0")
+        GENERATE_CPU_OBJECT(0x00, SCK0, CPU0)
+        GENERATE_CPU_OBJECT(0x01, SCK1, CPU1)
+        GENERATE_CPU_OBJECT(0x02, SCK2, CPU2)
+        GENERATE_CPU_OBJECT(0x03, SCK3, CPU3)
+        GENERATE_CPU_OBJECT(0x04, SCK4, CPU4)
+        GENERATE_CPU_OBJECT(0x05, SCK5, CPU5)
+        GENERATE_CPU_OBJECT(0x06, SCK6, CPU6)
+        GENERATE_CPU_OBJECT(0x07, SCK7, CPU7)
+        GENERATE_CPU_OBJECT(0x08, SCK8, CPU8)
+        GENERATE_CPU_OBJECT(0x09, SCK9, CPU9)
+        GENERATE_CPU_OBJECT(0x0a, SCKA, CPUA)
+        GENERATE_CPU_OBJECT(0x0b, SCKB, CPUB)
+        GENERATE_CPU_OBJECT(0x0c, SCKC, CPUC)
+        GENERATE_CPU_OBJECT(0x0d, SCKD, CPUD)
+        GENERATE_CPU_OBJECT(0x0e, SCKE, CPUE)
+        GENERATE_CPU_OBJECT(0x0f, SCKF, CPUF)
+        GENERATE_CPU_OBJECT(0x10, SCKG, CPUG)
+        GENERATE_CPU_OBJECT(0x11, SCKH, CPUH)
+        GENERATE_CPU_OBJECT(0x12, SCKI, CPUI)
+        GENERATE_CPU_OBJECT(0x13, SCKJ, CPUJ)
+        GENERATE_CPU_OBJECT(0x14, SCKK, CPUK)
+        GENERATE_CPU_OBJECT(0x15, SCKL, CPUL)
+        GENERATE_CPU_OBJECT(0x16, SCKM, CPUM)
+        GENERATE_CPU_OBJECT(0x17, SCKN, CPUN)
+        GENERATE_CPU_OBJECT(0x18, SCKO, CPUO)
+        GENERATE_CPU_OBJECT(0x19, SCKP, CPUP)
+        GENERATE_CPU_OBJECT(0x1a, SCKQ, CPUQ)
+        GENERATE_CPU_OBJECT(0x1b, SCKR, CPUR)
+        GENERATE_CPU_OBJECT(0x1c, SCKS, CPUS)
+        GENERATE_CPU_OBJECT(0x1d, SCKT, CPUT)
+        GENERATE_CPU_OBJECT(0x1e, SCKU, CPUU)
+        GENERATE_CPU_OBJECT(0x1f, SCKV, CPUV)
 
 #undef GENERATE_CPU_OBJECT
     }
