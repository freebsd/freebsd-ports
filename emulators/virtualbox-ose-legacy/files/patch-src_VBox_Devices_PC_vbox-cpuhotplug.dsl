--- src/VBox/Devices/PC/vbox-cpuhotplug.dsl.orig	2020-07-09 16:55:56 UTC
+++ src/VBox/Devices/PC/vbox-cpuhotplug.dsl
@@ -48,7 +48,7 @@ DefinitionBlock ("SSDT-cpuhotplug.aml", "SSDT", 1, "VB
     Device (sck)                                                           \
     {                                                                      \
         Name (_HID, "ACPI0004")                                            \
-        Name (_UID, sckuid)                                                \
+        Name (_UID, id)                                                    \
                                                                            \
         <NL>                                                               \
         Processor (cpu, /* Name */                                         \
