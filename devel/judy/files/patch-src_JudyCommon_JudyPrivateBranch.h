--- src/JudyCommon/JudyPrivateBranch.h.orig	2005-02-15 21:06:07 UTC
+++ src/JudyCommon/JudyPrivateBranch.h
@@ -55,7 +55,7 @@ typedef struct J_UDY_POINTER_OTHERS      // JPO.
         {
             Word_t      j_po_Addr;       // first word:  Pjp_t, Word_t, etc.
             union {
-//              Word_t  j_po_DcdPop0:cJU_BITSPERWORD-cJU_BITSPERBYTE;
+                Word_t  j_po_Addr1;
                 uint8_t j_po_DcdP0[sizeof(Word_t) - 1];
                 uint8_t j_po_Bytes[sizeof(Word_t)];     // last byte = jp_Type.
             } jpo_u;
@@ -78,13 +78,18 @@ typedef struct J_UDY_POINTER_OTHERS      // JPO.
 // TBD:  Revise this structure to not overload j_po_DcdPopO this way?  The
 // current arrangement works, its just confusing.
 
-typedef struct _JUDY_POINTER_IMMED      // JPI.
+typedef struct _JUDY_POINTER_IMMEDL  
         {
-            uint8_t j_pi_1Index[sizeof(Word_t)];        // see above.
-            uint8_t j_pi_LIndex[sizeof(Word_t) - 1];    // see above.
-            uint8_t j_pi_Type;                  // JP type, 1 of cJ*_JPIMMED*.
-        } jpi_t;
+            Word_t  j_pL_Addr;
+            uint8_t j_pL_LIndex[sizeof(Word_t) - 1];    // see above.
+            uint8_t j_pL_Type;
+        } jpL_t;
 
+typedef struct _JUDY_POINTER_IMMED1   
+        {
+            uint8_t j_p1_1Index[(2 * sizeof(Word_t)) - 1];
+            uint8_t j_p1_Type;
+        } jp1_t;
 
 // UNION OF JP TYPES:
 //
@@ -96,18 +101,22 @@ typedef struct _JUDY_POINTER_IMMED      // JPI.
 typedef union J_UDY_POINTER             // JP.
         {
             jpo_t j_po;                 // other than immediate indexes.
-            jpi_t j_pi;                 // immediate indexes.
+            jpL_t j_pL;                 // immediate indexes.
+            jp1_t j_p1;                 // immediate indexes.
         } jp_t, *Pjp_t;
 
 // For coding convenience:
 //
-// Note, jp_Type has the same bits in jpo_t and jpi_t.
+// Note, jp_Type has the same bits in jpo_t jpL_t and jp1_t.
 
-#define jp_1Index  j_pi.j_pi_1Index     // for storing Indexes in first  word.
-#define jp_LIndex  j_pi.j_pi_LIndex     // for storing Indexes in second word.
+#define jp_1Index  j_p1.j_p1_1Index     // for storing Indexes in first  word.
+#define jp_LIndex  j_pL.j_pL_LIndex     // for storing Indexes in second word.
 #define jp_Addr    j_po.j_po_Addr
+#define jp_Addr1   j_po.jpo_u.j_po_Addr1
 //#define       jp_DcdPop0 j_po.jpo_u.j_po_DcdPop0
-#define jp_Type    j_po.jpo_u.j_po_Bytes[sizeof(Word_t) - 1]
+#define jp_Addr1   j_po.jpo_u.j_po_Addr1
+//#define jp_Type    j_po.jpo_u.j_po_Bytes[sizeof(Word_t) - 1]
+#define jp_Type    j_p1.j_p1_Type
 #define jp_DcdP0   j_po.jpo_u.j_po_DcdP0
 
 
