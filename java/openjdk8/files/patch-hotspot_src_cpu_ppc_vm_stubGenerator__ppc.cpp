--- hotspot/src/cpu/ppc/vm/stubGenerator_ppc.cpp.orig	2019-07-22 16:46:38 UTC
+++ hotspot/src/cpu/ppc/vm/stubGenerator_ppc.cpp
@@ -1212,12 +1212,6 @@ class StubGenerator: public StubCodeGenerator {
       // Prefetch the data into the L2 cache.
       __ dcbt(R3_ARG1, 0);
 
-      // If supported set DSCR pre-fetch to deepest.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val | 7);
-        __ mtdscr(tmp2);
-      }
-
       __ li(tmp1, 16);
 
       // Backbranch target aligned to 32-byte. Not 16-byte align as
@@ -1236,12 +1230,6 @@ class StubGenerator: public StubCodeGenerator {
       __ addi(R4_ARG2, R4_ARG2, 32);       // Update dsc+=32
       __ bdnz(l_10);                       // Dec CTR and loop if not zero.
 
-      // Restore DSCR pre-fetch value.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val);
-        __ mtdscr(tmp2);
-      }
-
     } // VSX
    } // FasterArrayCopy
 
@@ -1481,11 +1469,6 @@ class StubGenerator: public StubCodeGenerator {
         // Prefetch src data into L2 cache.
         __ dcbt(R3_ARG1, 0);
 
-        // If supported set DSCR pre-fetch to deepest.
-        if (VM_Version::has_mfdscr()) {
-          __ load_const_optimized(tmp2, VM_Version::_dscr_val | 7);
-          __ mtdscr(tmp2);
-        }
         __ li(tmp1, 16);
 
         // Backbranch target aligned to 32-byte. It's not aligned 16-byte
@@ -1504,12 +1487,6 @@ class StubGenerator: public StubCodeGenerator {
         __ addi(R4_ARG2, R4_ARG2, 32);       // Update dsc+=32.
         __ bdnz(l_9);                        // Dec CTR and loop if not zero.
 
-        // Restore DSCR pre-fetch value.
-        if (VM_Version::has_mfdscr()) {
-          __ load_const_optimized(tmp2, VM_Version::_dscr_val);
-          __ mtdscr(tmp2);
-        }
-
       }
     } // FasterArrayCopy
     __ bind(l_6);
@@ -1674,12 +1651,6 @@ class StubGenerator: public StubCodeGenerator {
       // Prefetch the data into the L2 cache.
       __ dcbt(R3_ARG1, 0);
 
-      // If supported set DSCR pre-fetch to deepest.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val | 7);
-        __ mtdscr(tmp2);
-      }
-
       __ li(tmp1, 16);
 
       // Backbranch target aligned to 32-byte. Not 16-byte align as
@@ -1698,12 +1669,6 @@ class StubGenerator: public StubCodeGenerator {
       __ addi(R4_ARG2, R4_ARG2, 32);       // Update dsc+=32
       __ bdnz(l_7);                        // Dec CTR and loop if not zero.
 
-      // Restore DSCR pre-fetch value.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val);
-        __ mtdscr(tmp2);
-      }
-
     } // VSX
    } // FasterArrayCopy
 
@@ -1821,12 +1786,6 @@ class StubGenerator: public StubCodeGenerator {
       // Prefetch the data into the L2 cache.
       __ dcbt(R3_ARG1, 0);
 
-      // If supported set DSCR pre-fetch to deepest.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val | 7);
-        __ mtdscr(tmp2);
-      }
-
       __ li(tmp1, 16);
 
       // Backbranch target aligned to 32-byte. Not 16-byte align as
@@ -1845,11 +1804,6 @@ class StubGenerator: public StubCodeGenerator {
       __ stxvd2x(tmp_vsr1, R4_ARG2);       // Store to dst
       __ bdnz(l_4);
 
-      // Restore DSCR pre-fetch value.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val);
-        __ mtdscr(tmp2);
-      }
      }
 
       __ cmpwi(CCR0, R5_ARG3, 0);
@@ -1949,12 +1903,6 @@ class StubGenerator: public StubCodeGenerator {
       // Prefetch the data into the L2 cache.
       __ dcbt(R3_ARG1, 0);
 
-      // If supported set DSCR pre-fetch to deepest.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val | 7);
-        __ mtdscr(tmp2);
-      }
-
       __ li(tmp1, 16);
 
       // Backbranch target aligned to 32-byte. Not 16-byte align as
@@ -1973,12 +1921,6 @@ class StubGenerator: public StubCodeGenerator {
       __ addi(R4_ARG2, R4_ARG2, 32);       // Update dsc+=32
       __ bdnz(l_5);                        // Dec CTR and loop if not zero.
 
-      // Restore DSCR pre-fetch value.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val);
-        __ mtdscr(tmp2);
-      }
-
     } // VSX
    } // FasterArrayCopy
 
@@ -2074,12 +2016,6 @@ class StubGenerator: public StubCodeGenerator {
       // Prefetch the data into the L2 cache.
       __ dcbt(R3_ARG1, 0);
 
-      // If supported set DSCR pre-fetch to deepest.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val | 7);
-        __ mtdscr(tmp2);
-      }
-
       __ li(tmp1, 16);
 
       // Backbranch target aligned to 32-byte. Not 16-byte align as
@@ -2098,11 +2034,6 @@ class StubGenerator: public StubCodeGenerator {
       __ stxvd2x(tmp_vsr1, R4_ARG2);       // Store to dst
       __ bdnz(l_4);
 
-      // Restore DSCR pre-fetch value.
-      if (VM_Version::has_mfdscr()) {
-        __ load_const_optimized(tmp2, VM_Version::_dscr_val);
-        __ mtdscr(tmp2);
-      }
      }
 
       __ cmpwi(CCR0, R5_ARG3, 0);
