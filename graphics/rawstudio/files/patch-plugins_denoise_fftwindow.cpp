--- plugins/denoise/fftwindow.cpp.orig	2011-02-15 17:28:03 UTC
+++ plugins/denoise/fftwindow.cpp
@@ -174,7 +174,7 @@ void FFTWindow::applyAnalysisWindowSSE( 
     if ((uintptr_t)src1 & 15) {
       asm volatile 
       ( 
-      "loop_analysis_sse_ua:\n"
+      "1:\n"
       "prefetchnta (%4)\n"        // Prefetch next line (Used once only, so don't pollute cache)
       "movups (%1), %%xmm0\n"       // src1 pt1
       "movups 16(%1), %%xmm1\n"     // src1 pt2 
@@ -193,7 +193,7 @@ void FFTWindow::applyAnalysisWindowSSE( 
       "add $64, %2\n"
       "add $64, %4\n"
       "dec %3\n"
-      "jnz loop_analysis_sse_ua\n"
+      "jnz 1b\n"
 
       : /* no output registers */
       : "r" (analysis.getLine(y)), "r" (src1),  "r" (dst->getLine(y)), "r" (sizew), "r" (&src1[image->pitch])
@@ -202,7 +202,7 @@ void FFTWindow::applyAnalysisWindowSSE( 
     } else {
     asm volatile 
       ( 
-      "loop_analysis_sse_a:\n"
+      "1:\n"
       "prefetchnta (%4)\n"        // Prefetch next line (Used once only, so don't pollute cache)
       "movaps (%1), %%xmm0\n"       // src1 pt1
       "movaps 16(%1), %%xmm1\n"     // src1 pt2 
@@ -221,7 +221,7 @@ void FFTWindow::applyAnalysisWindowSSE( 
       "add $64, %2\n"
       "add $64, %4\n"
       "dec %3\n"
-      "jnz loop_analysis_sse_a\n"
+      "jnz 1b\n"
 
       : /* no output registers */
       : "r" (analysis.getLine(y)), "r" (src1),  "r" (dst->getLine(y)), "r" (sizew), "r" (&src1[image->pitch])
