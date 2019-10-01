--- src/fractalalgorithminterface.cc.orig	2019-09-01 12:19:42 UTC
+++ src/fractalalgorithminterface.cc
@@ -23,6 +23,7 @@
 #include "fractalalgorithminterface.h"
 #include "uintconfigentry.h"
 
+#include <algorithm>
 
 QList<FractalAlgorithmInterface*>* FractalAlgorithmInterface::AlgorithmList = nullptr;
 bool                               FractalAlgorithmInterface::Updated       = false;
@@ -100,7 +101,7 @@ static bool lessThan(const FractalAlgorithmInterface* 
 FractalAlgorithmInterface* FractalAlgorithmInterface::getAlgorithm(const unsigned int index)
 {
    if(Updated) {
-      qSort(AlgorithmList->begin(), AlgorithmList->end(), lessThan);
+      std::sort(AlgorithmList->begin(), AlgorithmList->end(), lessThan);
       Updated = false;
    }
    return(AlgorithmList->value(index, nullptr));
