--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Sets.c	Tue Feb 15 14:26:59 1994
+++ ./reuse/m2c/Sets.c	Thu Aug  5 18:49:34 2004
@@ -16,10 +16,10 @@
 #include "Sets.h"
 #endif
 
+static int BitsPerBitset;
+static int BitsPerByte; 
+static int BytesPerBitset;
 
-#define BitsPerBitset	32
-#define BitsPerByte	8
-#define BytesPerBitset	(BitsPerBitset / BitsPerByte)
 #define NoCard	-1
 static BITSET AllBits;
 static IO_tFile g;
@@ -713,8 +713,8 @@
     }
     Sets_Include(Set, (LONGCARD)IO_ReadI(f));
     INC(card);
-  } EXIT_1:;
   Set->Card = card;
+  } EXIT_1:;
 }
 
 void Sets_WriteSet
@@ -726,14 +726,10 @@
 Sets_tSet Set;
 # endif
 {
-  {
-    register Sets_tSet *W_23 = &Set;
-
     g = f;
     IO_WriteC(f, '{');
     Sets_ForallDo(Set, (Sets_ProcOfCard)WriteElmt);
     IO_WriteC(f, '}');
-  }
 }
 
 static void WriteElmt
@@ -750,18 +746,30 @@
 
 void BEGIN_Sets()
 {
+  int t = SYSTEM_MaxSet;
+
   static BOOLEAN has_been_called = FALSE;
   if (has_been_called) return;
   has_been_called = TRUE;
+  
+  AllBits = ~(0x0UL);
+  BitsPerByte	 = 8; 
+  BytesPerBitset = sizeof(BITSET);
+  BitsPerBitset  = BytesPerBitset*BitsPerByte;
+
     BEGIN_IO();
     BEGIN_General();
     BEGIN_DynArray();
     BEGIN_IO();
 
-    AllBits = SET_cRNG(0, BitsPerBitset - 1);
-    if (sizeof(BITSET) < BytesPerBitset) {
-      IO_WriteS((rSystem_tFile)IO_StdError, (STRING)"Sets: TSIZE (BITSET) = ", 23L);
+
+    if ((int)sizeof(BITSET) < BytesPerBitset) {
+      IO_WriteS((rSystem_tFile)IO_StdError, (STRING)"Sets:  SIZE (BITSET) = ", 23L);
       IO_WriteI((rSystem_tFile)IO_StdError, (LONGINT)sizeof(BITSET), 0L);
       IO_WriteNl((rSystem_tFile)IO_StdError);
+      IO_WriteS((rSystem_tFile)IO_StdError, (STRING)"Sets: SYSTEM_MaxSet  = ", 23L);
+      IO_WriteI((rSystem_tFile)IO_StdError, t, 0L);
+      IO_WriteNl((rSystem_tFile)IO_StdError);
     }
 }
+
