--- src/VBox/Devices/PC/vbox-cpuhotplug.dsl.orig	2016-04-20 10:01:38 UTC
+++ src/VBox/Devices/PC/vbox-cpuhotplug.dsl
@@ -27,16 +27,28 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", 
         Return(LEqual(CPUL, 0x01))
     }
 
+    // Method to notify the VMM that a CPU is not
+    // in use anymore and can be safely removed.
+    // Using the extra method here because the CPUL
+    // register identifer clashes with the CPUL object defined
+    // below making iasl starting with version 20150930 fail.
+    //
+    // Think of CPLO as "CPU Lock Open"
+    Method(CPLO, 1)
+    {
+        Store(Arg0, CPUL)
+    }
+
     Scope (\_SB)
     {
 
-#define GENERATE_CPU_OBJECT(id, sck, sckuid, cpu, cpuuid)                  \
+#define GENERATE_CPU_OBJECT(id, sck, sckuid, cpu, cpuuid)<NL>              \
     Device (sck)                                                           \
     {                                                                      \
         Name (_HID, "ACPI0004")                                            \
         Name (_UID, sckuid)                                                \
                                                                            \
-                                                                           \
+        <NL>                                                               \
         Processor (cpu, /* Name */                                         \
                    id,  /* Id */                                           \
                    0x0, /* Processor IO ports range start */               \
@@ -46,8 +58,8 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", 
             Name (_HID, "ACPI0007")                                        \
             Name (_UID, cpuuid)                                            \
             Name (_PXM, 0x00)                                              \
-                                                                           \
-            Method(_MAT, 0)                                                \
+            <NL>                                                           \
+            Method(_MAT, 0, Serialized)                                    \
             {                                                              \
                 Name (APIC, Buffer (8) {0x00, 0x08, id, id})               \
                 IF (CPCK(id))                                              \
@@ -60,6 +72,7 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", 
                 }                                                          \
                 Return (APIC)                                              \
             }                                                              \
+            <NL>                                                           \
             Method(_STA) /* Used for device presence detection */          \
             {                                                              \
                 IF (CPCK(id))                                              \
@@ -71,9 +84,10 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", 
                     Return (0x0)                                           \
                 }                                                          \
             }                                                              \
+            <NL>                                                           \
             Method(_EJ0, 1)                                                \
             {                                                              \
-                Store(id, CPUL) /* Unlock the CPU */                       \
+                CPLO(id) /* Unlock the CPU */                              \
                 Return                                                     \
             }                                                              \
         }                                                                  \
