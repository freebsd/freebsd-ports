--- src/VBox/Devices/PC/vbox.dsl.orig	2010-03-25 15:56:03.000000000 -0400
+++ src/VBox/Devices/PC/vbox.dsl	2010-04-29 19:14:38.000000000 -0400
@@ -1064,7 +1064,7 @@
                              // (all of low memory space)
                      ResourceProducer,        // bit 0 of general flags is 0
                      PosDecode,               // positive Decode
-                     MinFixed,                // Range is fixed
+                     MinNotFixed,             // Range is not fixed
                      MaxFixed,                // Range is fixed
                      Cacheable,
                      ReadWrite,
@@ -1073,7 +1073,7 @@
 
                      0xffdfffff,              // Max = 4GB - 2MB
                      0x00000000,              // Translation
-                     0xdfdfffff,              // Range Length (calculated
+                     0x00000000,              // Range Length (calculated
                                               // dynamically)
                      ,                        // Optional field left blank
                      ,                        // Optional field left blank
