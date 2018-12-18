--- client/pulsefind.h.orig	2018-12-18 12:03:47 UTC
+++ client/pulsefind.h
@@ -82,7 +82,6 @@ extern FoldSet AVXfold_c;       // in analyzeFuncs_avx
 extern FoldSet sse_ben_fold;    // in analyzeFuncs_sse.cpp
 extern FoldSet BHSSEfold;       // in analyzeFuncs_sse.cpp
 extern FoldSet AKSSEfold;       // in analyzeFuncs_sse.cpp
-extern FoldSet AKavfold;        // in analyzeFuncs_altivec.cpp
 extern FoldSet swifold;         // in Pulsefind - default set
 extern FoldSet Foldmain;        // in Pulsefind - used set
 
