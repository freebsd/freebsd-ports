--- src/emucore/m6502/src/M6502.cxx.orig	Tue Feb 18 10:19:44 2003
+++ src/emucore/m6502/src/M6502.cxx	Wed Sep 17 00:45:41 2003
@@ -128,7 +128,7 @@
 }
 
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-ostream& operator<<(ostream& out, const M6502::AddressingMode& mode)
+std::ostream& operator<<(std::ostream& out, const M6502::AddressingMode& mode)
 {
   switch(mode)
   {
