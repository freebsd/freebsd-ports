--- src/emucore/m6502/src/M6502.hxx.orig	Tue Feb 18 10:19:44 2003
+++ src/emucore/m6502/src/M6502.hxx	Wed Sep 17 00:45:41 2003
@@ -164,7 +164,7 @@
       @param out The stream to output the addressing mode to
       @param mode The addressing mode to output
     */
-    friend ostream& operator<<(ostream& out, const AddressingMode& mode);
+    friend std::ostream& operator<<(std::ostream& out, const AddressingMode& mode);
 
   protected:
     /**
