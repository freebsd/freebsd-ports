--- ext/bifrost/src/BooPHF.h.orig	2026-02-26 17:50:47 UTC
+++ ext/bifrost/src/BooPHF.h
@@ -8,6 +8,7 @@
 #include <stdlib.h>
 #include <iostream>
 #include <math.h>
+#include <inttypes.h>
 
 #include <array>
 #include <unordered_map>
@@ -533,11 +534,11 @@ we need this 2-functors scheme because HashFunctors wo
         //for debug purposes
         void print() const
         {
-            printf("bit array of size %llu: \n",_size);
+            printf("bit array of size %" PRIu64 ": \n",_size);
             for(uint64_t ii = 0; ii< _size; ii++)
             {
                 if(ii%10==0)
-                    printf(" (%llu) ",ii);
+                    printf(" (%" PRIu64 ") ",ii);
                 int val = (_bitArray[ii >> 6] >> (ii & 63 ) ) & 1;
                 printf("%i",val);
             }
@@ -546,7 +547,7 @@ we need this 2-functors scheme because HashFunctors wo
             printf("rank array : size %lu \n",_ranks.size());
             for (uint64_t ii = 0; ii< _ranks.size(); ii++)
             {
-                printf("%llu :  %llu,  ",ii,_ranks[ii]);
+                printf("%" PRIu64 " :  %" PRIu64 ",  ",ii,_ranks[ii]);
             }
             printf("\n");
         }
