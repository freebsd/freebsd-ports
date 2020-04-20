--- lib/voice.cc.orig	2020-04-20 02:49:05 UTC
+++ lib/voice.cc
@@ -23,6 +23,8 @@
 #include "voice.hh"
 #include "synth.hh"
 
+#include <array>
+
 using namespace LiquidSFZInternal;
 
 double
