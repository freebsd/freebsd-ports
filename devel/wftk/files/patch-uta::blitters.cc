--- uta/blitters.cc.orig	Sat Oct 12 23:11:07 2002
+++ uta/blitters.cc	Sat Jul 26 01:16:18 2003
@@ -20,6 +20,7 @@
 
 #include "blitters.h"
 #include <painter.h>
+#include <cassert>
 
 namespace uta {
 
@@ -27,6 +28,8 @@
 #undef X86_ASSEMBLER
 #endif
 #if !defined(X86_ASSEMBLER)
+
+using namespace std;
 
 /** Apply const gamma value.
     Blit just copies alpha value of the source to the destination surface.
