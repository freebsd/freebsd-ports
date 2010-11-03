Workaround for an regression in acpica 20101015.

Compile error:
kBuild: iasl DevicesR3 - src/VBox/Devices/PC/vbox.dsl
   736:                           Name (_CID, "smc-napa")
Error 4001 - String must be entirely alphanumeric ^
(smc-napa)

See: http://lists.freebsd.org/pipermail/freebsd-acpi/2010-October/006795.html

--- src/VBox/Devices/PC/vbox.dsl.orig	2010-10-08 22:10:12.000000000 +0200
+++ src/VBox/Devices/PC/vbox.dsl	2010-10-27 14:45:38.000000000 +0200
@@ -733,7 +733,7 @@
                 Device (SMC)
                 {
                     Name (_HID, EisaId ("APP0001"))
-                    Name (_CID, "smc-napa")
+                    Name (_CID, "smcnapa")
 
                     Method (_STA, 0, NotSerialized)
                     {
