--- src/slm/thread/slmthread.cpp.orig	2014-11-14 14:17:48 UTC
+++ src/slm/thread/slmthread.cpp
@@ -250,10 +250,10 @@ main(int argc, char* argv[])
 
     bool usingLogPr = slm.isUseLogPr();
 
-    #define EffectivePr(a)  (float((usingLogPr) ? ((a) / log(2.0)) : (-log2((a)))))
-    #define OriginalPr(b)   (float((usingLogPr) ? ((b) * log(2.0)) : (exp2(-(b)))))
-    #define EffectiveBow(a) (float((usingLogPr) ? (exp(-(a))) : ((a))))
-    #define OriginalBow(b)  (float((usingLogPr) ? (-log((b))) : ((b))))
+    #define EffectivePr(a)  (float((usingLogPr) ? ((a) / logf(2.0f)) : (-log2f((a)))))
+    #define OriginalPr(b)   (float((usingLogPr) ? ((b) * logf(2.0f)) : (exp2f(-(b)))))
+    #define EffectiveBow(a) (float((usingLogPr) ? (expf(-(a))) : ((a))))
+    #define OriginalBow(b)  (float((usingLogPr) ? (-logf((b))) : ((b))))
 
     printf("\nfirst pass..."); fflush(stdout);
     for (int lvl = 0; lvl <= slm.getN(); ++lvl) {
