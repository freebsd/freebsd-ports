--- pnggccrd.c.old	Thu Oct  3 15:32:28 2002
+++ pnggccrd.c	Sat Jul 24 14:07:13 2004
@@ -1767,7 +1767,8 @@
 
                         : "1" (sptr),      // esi      // input regs
                           "2" (dp),        // edi
-                          "0" (width)      // ecx
+                          "0" (width),      // ecx
+                          "rim" (_const4)
 // doesn't work           "i" (0x0000000000FFFFFFLL)   // %1 (a.k.a. _const4)
 
 #if 0  /* %mm0, ..., %mm4 not supported by gcc 2.7.2.3 or egcs 1.1 */
@@ -1811,7 +1812,8 @@
 
                         : "1" (sptr),      // esi      // input regs
                           "2" (dp),        // edi
-                          "0" (width)      // ecx
+                          "0" (width),     // ecx
+                          "rim" (_const4)
 
 #if 0  /* %mm0, ..., %mm2 not supported by gcc 2.7.2.3 or egcs 1.1 */
                         : "%mm0", "%mm1", "%mm2"       // clobber list
@@ -1865,7 +1867,9 @@
 
                            : "1" (sptr),      // esi      // input regs
                              "2" (dp),        // edi
-                             "0" (width_mmx)  // ecx
+                             "0" (width_mmx), // ecx
+                             "rim" (_const4),
+                             "rim" (_const6)
 
 #if 0  /* %mm0, ..., %mm3 not supported by gcc 2.7.2.3 or egcs 1.1 */
                            : "%mm0", "%mm1"               // clobber list
@@ -4529,8 +4533,7 @@
       : "0" (bpp),              // eax    // input regs
         "1" (row)               // edi
 
-      : "%ebx", "%ecx", "%edx"            // clobber list
-      , "%esi"
+      : "%esi", "%ecx", "%edx"            // clobber list
 
 #if 0  /* MMX regs (%mm0, etc.) not supported by gcc 2.7.2.3 or egcs 1.1 */
       , "%mm0", "%mm1", "%mm2", "%mm3"
@@ -5034,7 +5037,10 @@
         "1" (prev_row),         // esi
         "2" (row)               // edi
 
-      : "%eax", "%ebx", "%ecx"            // clobber list (no input regs!)
+      : "%eax", "%ecx"            // clobber list (no input regs!)
+#ifndef __PIC__
+      , "%ebx"
+#endif
 
 #if 0  /* MMX regs (%mm0, etc.) not supported by gcc 2.7.2.3 or egcs 1.1 */
       , "%mm0", "%mm1", "%mm2", "%mm3"
