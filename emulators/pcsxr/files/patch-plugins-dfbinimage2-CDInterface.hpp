--- plugins/dfbinimage2/CDInterface.hpp.orig	2011-07-20 07:24:23.758738346 +0200
+++ plugins/dfbinimage2/CDInterface.hpp	2011-07-20 07:26:37.053050612 +0200
@@ -46,7 +46,8 @@
             // track info.  fyi, tester is my testing/development program.
             std::string programName = getProgramName();
             if ( programName == "epsxe" || programName == "pcsx"  ||
-                 programName == "pcsx2" || programName == "tester" )
+                 programName == "pcsx2" || programName == "tester"||
+                 programName == "pcsxr" )
                 tdtnformat = fsmint;
             else
                 tdtnformat = msfbcd;
