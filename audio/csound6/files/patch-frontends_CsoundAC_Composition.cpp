--- frontends/CsoundAC/Composition.cpp.orig	2015-09-29 11:13:28 UTC
+++ frontends/CsoundAC/Composition.cpp
@@ -22,6 +22,7 @@
 #endif
 #include "Composition.hpp"
 #include "System.hpp"
+#include <cstdio>
 #include <cstdlib>
 #include <map>
 
@@ -289,7 +290,7 @@ namespace csound
   int Composition::normalizeOutputSoundfile(double levelDb)
   {
     char buffer[0x100];
-    std::snprintf(buffer,
+    snprintf(buffer,
                   0x100,
                   "sox %s -V3 -b 32 -e floating-point %s gain -n %f\n",
                   getOutputSoundfileName().c_str(),
@@ -307,7 +308,7 @@ namespace csound
   int Composition::translateToCdAudio(double levelDb)
   {
     char buffer[0x100];
-    std::snprintf(buffer, 0x100, "sox %s -V3 -b 16 %s gain -n %f rate 44100\n",
+    snprintf(buffer, 0x100, "sox %s -V3 -b 16 %s gain -n %f rate 44100\n",
                   getOutputSoundfileName().c_str(),
                   getCdSoundfileName().c_str(),
                   levelDb);
@@ -323,7 +324,7 @@ namespace csound
   int Composition::translateToMp3(double bitrate, double levelDb)
   {
     char buffer[0x100];
-    std::snprintf(buffer,
+    snprintf(buffer,
                   0x100,
                   "lame --verbose --disptime 2 --nohist --preset cd --tt %s --ta %s --tl %s --tc %s %s %s\n",
                   getTitle().c_str(),
