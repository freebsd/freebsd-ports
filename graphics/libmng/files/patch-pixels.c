This changes the behaviour to what appears to be the original intent...

	-mi

--- libmng_pixels.c	2012-07-29 15:26:34.000000000 -0400
+++ libmng_pixels.c	2024-01-08 14:21:18.664893000 -0500
@@ -14669,5 +14669,5 @@
 
     *pDstline     = (mng_uint8)(iW >> 8);
-    *(pDstline+1) = (mng_uint8)(iW && 0xFF);
+    *(pDstline+1) = (mng_uint8)(iW & 0xFF);
 
     pSrcline++;
@@ -14787,5 +14787,5 @@
 
     *pDstline     = (mng_uint8)(iW >> 8);
-    *(pDstline+1) = (mng_uint8)(iW && 0xFF);
+    *(pDstline+1) = (mng_uint8)(iW & 0xFF);
 
     pSrcline++;
@@ -14908,5 +14908,5 @@
     *(pDstline+2) = iB;
     *(pDstline+4) = iB;
-    iB            = (mng_uint8)(iW && 0xFF);
+    iB            = (mng_uint8)(iW & 0xFF);
     *(pDstline+1) = iB;
     *(pDstline+3) = iB;
@@ -15042,5 +15042,5 @@
     *(pDstline+2) = iB;
     *(pDstline+4) = iB;
-    iB            = (mng_uint8)(iW && 0xFF);
+    iB            = (mng_uint8)(iW & 0xFF);
     *(pDstline+1) = iB;
     *(pDstline+3) = iB;
@@ -15126,7 +15126,7 @@
 
     *pDstline     = (mng_uint8)(iW >> 8);
-    *(pDstline+1) = (mng_uint8)(iW && 0xFF);
+    *(pDstline+1) = (mng_uint8)(iW & 0xFF);
     *(pDstline+2) = (mng_uint8)(iA >> 8);
-    *(pDstline+3) = (mng_uint8)(iA && 0xFF);
+    *(pDstline+3) = (mng_uint8)(iA & 0xFF);
 
     pSrcline += 2;
@@ -15210,10 +15210,10 @@
     *(pDstline+2) = iB;
     *(pDstline+4) = iB;
-    iB            = (mng_uint8)(iW && 0xFF);
+    iB            = (mng_uint8)(iW & 0xFF);
     *(pDstline+1) = iB;
     *(pDstline+3) = iB;
     *(pDstline+5) = iB;
     *(pDstline+6) = (mng_uint8)(iA >> 8);
-    *(pDstline+7) = (mng_uint8)(iA && 0xFF);
+    *(pDstline+7) = (mng_uint8)(iA & 0xFF);
 
     pSrcline += 2;
@@ -15297,9 +15297,9 @@
 
     *pDstline     = (mng_uint8)(iR >> 8);
-    *(pDstline+1) = (mng_uint8)(iR && 0xFF);
+    *(pDstline+1) = (mng_uint8)(iR & 0xFF);
     *(pDstline+2) = (mng_uint8)(iG >> 8);
-    *(pDstline+3) = (mng_uint8)(iG && 0xFF);
+    *(pDstline+3) = (mng_uint8)(iG & 0xFF);
     *(pDstline+4) = (mng_uint8)(iB >> 8);
-    *(pDstline+5) = (mng_uint8)(iB && 0xFF);
+    *(pDstline+5) = (mng_uint8)(iB & 0xFF);
 
     pSrcline += 3;
@@ -15402,9 +15402,9 @@
 
     *pDstline     = (mng_uint8)(iRw >> 8);
-    *(pDstline+1) = (mng_uint8)(iRw && 0xFF);
+    *(pDstline+1) = (mng_uint8)(iRw & 0xFF);
     *(pDstline+2) = (mng_uint8)(iGw >> 8);
-    *(pDstline+3) = (mng_uint8)(iGw && 0xFF);
+    *(pDstline+3) = (mng_uint8)(iGw & 0xFF);
     *(pDstline+4) = (mng_uint8)(iBw >> 8);
-    *(pDstline+5) = (mng_uint8)(iBw && 0xFF);
+    *(pDstline+5) = (mng_uint8)(iBw & 0xFF);
 
     pSrcline += 3;
@@ -15539,9 +15539,9 @@
       iB              = ((mng_bitdepth_16)pData->fPromBitdepth) (pBuf->aPLTEentries [iN].iBlue);
       *pDstline       = (mng_uint8)(iR >> 8);
-      *(pDstline+1)   = (mng_uint8)(iR && 0xFF);
+      *(pDstline+1)   = (mng_uint8)(iR & 0xFF);
       *(pDstline+2)   = (mng_uint8)(iG >> 8);
-      *(pDstline+3)   = (mng_uint8)(iG && 0xFF);
+      *(pDstline+3)   = (mng_uint8)(iG & 0xFF);
       *(pDstline+4)   = (mng_uint8)(iB >> 8);
-      *(pDstline+5)   = (mng_uint8)(iB && 0xFF);
+      *(pDstline+5)   = (mng_uint8)(iB & 0xFF);
     }
 
@@ -15642,11 +15642,11 @@
 
       *pDstline     = (mng_uint8)(iR >> 8);
-      *(pDstline+1) = (mng_uint8)(iR && 0xFF);
+      *(pDstline+1) = (mng_uint8)(iR & 0xFF);
       *(pDstline+2) = (mng_uint8)(iG >> 8);
-      *(pDstline+3) = (mng_uint8)(iG && 0xFF);
+      *(pDstline+3) = (mng_uint8)(iG & 0xFF);
       *(pDstline+4) = (mng_uint8)(iB >> 8);
-      *(pDstline+5) = (mng_uint8)(iB && 0xFF);
+      *(pDstline+5) = (mng_uint8)(iB & 0xFF);
       *(pDstline+6) = (mng_uint8)(iA >> 8);
-      *(pDstline+7) = (mng_uint8)(iA && 0xFF);
+      *(pDstline+7) = (mng_uint8)(iA & 0xFF);
     }
 
@@ -15690,11 +15690,11 @@
 
     *pDstline     = (mng_uint8)(iR >> 8);
-    *(pDstline+1) = (mng_uint8)(iR && 0xFF);
+    *(pDstline+1) = (mng_uint8)(iR & 0xFF);
     *(pDstline+2) = (mng_uint8)(iG >> 8);
-    *(pDstline+3) = (mng_uint8)(iG && 0xFF);
+    *(pDstline+3) = (mng_uint8)(iG & 0xFF);
     *(pDstline+4) = (mng_uint8)(iB >> 8);
-    *(pDstline+5) = (mng_uint8)(iB && 0xFF);
+    *(pDstline+5) = (mng_uint8)(iB & 0xFF);
     *(pDstline+6) = (mng_uint8)(iA >> 8);
-    *(pDstline+7) = (mng_uint8)(iA && 0xFF);
+    *(pDstline+7) = (mng_uint8)(iA & 0xFF);
 
     pSrcline += 4;
