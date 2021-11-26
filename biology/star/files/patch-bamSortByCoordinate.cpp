--- bamSortByCoordinate.cpp.orig	2021-11-26 16:17:37 UTC
+++ bamSortByCoordinate.cpp
@@ -64,7 +64,7 @@ void bamSortByCoordinate (Parameters &P, ReadAlignChun
                             boolWait=false;
                             totalMem+=newMem;
                         };
-                        sleep(0.1);
+                        usleep(10000);
                     };
                     BAMbinSortByCoordinate(ibin,binN,binS,P.runThreadN,P.outBAMsortTmpDir, P, genome, solo);
                     #pragma omp critical
