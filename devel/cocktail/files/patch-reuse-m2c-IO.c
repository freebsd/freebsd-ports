--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/IO.c	Tue Feb 15 14:26:52 1994
+++ ./reuse/m2c/IO.c	Thu Aug  5 18:49:33 2004
@@ -36,7 +36,7 @@
 static struct S_2 {
     BufferDescriptor A[rSystem_cMaxFile - -1 + 1];
 } BufferPool;
-static IO_tFile i;
+static IO_tFile iof;
 static struct S_3 {
     CHAR A[15 + 1];
 } MyCHR;
@@ -162,7 +162,7 @@
         return i;
       }
       INC(i);
-    } EXIT_1:;
+    };
   }
 }
 
@@ -475,8 +475,6 @@
 IO_tFile f;
 # endif
 {
-  CHAR ch;
-
   {
     register BufferDescriptor *W_7 = &BufferPool.A[f - -1];
 
@@ -621,7 +619,7 @@
 
     INC(W_12->BufferIndex);
     W_12->Buffer->A[W_12->BufferIndex] = c;
-    if (W_12->BufferIndex == BufferSize || W_12->FlushLine && c == EolCh) {
+    if ((W_12->BufferIndex == BufferSize) || (W_12->FlushLine && c == EolCh)) {
       IO_WriteFlush(f);
     }
   }
@@ -895,7 +893,7 @@
           }
           INC(W_13->BufferIndex);
           W_13->Buffer->A[W_13->BufferIndex] = c;
-          if (W_13->BufferIndex == BufferSize || W_13->FlushLine && c == EolCh) {
+          if ((W_13->BufferIndex == BufferSize) || (W_13->FlushLine && c == EolCh)) {
             IO_WriteFlush(f);
           }
           if (i >= B_20) break;
@@ -1025,9 +1023,9 @@
     MyCHR.A[13] = 'D';
     MyCHR.A[14] = 'E';
     MyCHR.A[15] = 'F';
-    for (i = 0; i <= rSystem_cMaxFile; i += 1) {
+    for (iof = 0; iof <= rSystem_cMaxFile; iof += 1) {
       {
-        register BufferDescriptor *W_15 = &BufferPool.A[i - -1];
+        register BufferDescriptor *W_15 = &BufferPool.A[iof - -1];
 
         W_15->Buffer = NIL;
         W_15->BufferIndex = 0;
