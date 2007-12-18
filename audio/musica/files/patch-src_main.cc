--- src/main.cc.orig	2007-12-18 19:46:50.000000000 +0100
+++ src/main.cc	2007-12-18 19:48:06.000000000 +0100
@@ -59,7 +59,7 @@
 
 
 
-
+static char deviceName[] = "/dev/sequencer";
 
 int main(int argc, char *argv[])
 {
@@ -79,7 +79,7 @@
   // create some MIDI devices
   // first a "real" device: the Roland HP330 on the external MIDI port
   rolandHp330 = new ossSequencer("External MIDI port");
-  rolandHp330->setDevice("/dev/sequencer", 0);
+  rolandHp330->setDevice(deviceName, 0);
   rolandHp330->open();
   
   // map all channels on channel 0 (the default receive channel)
@@ -98,7 +98,7 @@
 
   // another "real" device: the EMU 8000 synthesiser on the SB 64 AWE Gold
   sbAwe64 = new ossSequencer("SB AWE 64");
-  sbAwe64->setDevice("/dev/sequencer", 1);
+  sbAwe64->setDevice(deviceName, 1);
   sbAwe64->open();
 
 
