--- IlmImf/ImfFastHuf.cpp.orig	2017-11-17 23:00:24 UTC
+++ IlmImf/ImfFastHuf.cpp
@@ -107,7 +107,7 @@ FastHufDecoder::FastHufDecoder
     for (int i = 0; i <= MAX_CODE_LEN; ++i)
     {
         codeCount[i] = 0;
-        base[i]      = 0xffffffffffffffffL;
+        base[i]      = 0xffffffffffffffffULL;
         offset[i]    = 0;
     }
 
@@ -352,7 +352,7 @@ FastHufDecoder::buildTables (Int64 *base
 
     for (int i = 0; i <= MAX_CODE_LEN; ++i)
     {
-        if (base[i] != 0xffffffffffffffffL)
+        if (base[i] != 0xffffffffffffffffULL)
         {
             _ljBase[i] = base[i] << (64 - i);
         }
@@ -362,7 +362,7 @@ FastHufDecoder::buildTables (Int64 *base
             // Unused code length - insert dummy values
             //
 
-            _ljBase[i] = 0xffffffffffffffffL;
+            _ljBase[i] = 0xffffffffffffffffULL;
         }
     }
 
@@ -417,7 +417,7 @@ FastHufDecoder::buildTables (Int64 *base
 
     int minIdx = TABLE_LOOKUP_BITS;
 
-    while (minIdx > 0 && _ljBase[minIdx] == 0xffffffffffffffffL)
+    while (minIdx > 0 && _ljBase[minIdx] == 0xffffffffffffffffULL)
         minIdx--;
 
     if (minIdx < 0)
@@ -427,7 +427,7 @@ FastHufDecoder::buildTables (Int64 *base
         // Set the min value such that the table is never tested.
         //
 
-        _tableMin = 0xffffffffffffffffL;
+        _tableMin = 0xffffffffffffffffULL;
     }
     else
     {
