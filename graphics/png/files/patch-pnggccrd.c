--- pnggccrd.c.orig	Thu Dec  4 15:52:22 2003
+++ pnggccrd.c	Thu Dec  4 16:00:18 2003
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
