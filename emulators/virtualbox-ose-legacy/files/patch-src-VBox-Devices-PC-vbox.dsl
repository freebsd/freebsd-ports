--- src/VBox/Devices/PC/vbox.dsl.orig	2011-04-28 10:00:53.000000000 +0200
+++ src/VBox/Devices/PC/vbox.dsl	2011-07-25 19:36:06.000000000 +0200
@@ -1161,7 +1161,7 @@
                              // (all of low memory space)
                      ResourceProducer,        // bit 0 of general flags is 0
                      PosDecode,               // positive Decode
-                     MinNotFixed,             // Range is not fixed
+                     MinFixed,                // Range is not fixed
                      MaxFixed,                // Range is fixed
                      Cacheable,
                      ReadWrite,
@@ -1170,7 +1170,7 @@
 
                      0xffdfffff,              // Max = 4GB - 2MB
                      0x00000000,              // Translation
-                     0x00000000,              // Range Length (calculated
+                     0xffe00000,              // Range Length (calculated
                                               // dynamically)
                      ,                        // Optional field left blank
                      ,                        // Optional field left blank
