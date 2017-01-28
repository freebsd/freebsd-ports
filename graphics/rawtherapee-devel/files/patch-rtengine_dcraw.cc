--- rtengine/dcraw.cc.orig	2016-12-30 15:28:53 UTC
+++ rtengine/dcraw.cc
@@ -2011,7 +2011,7 @@ void CLASS hasselblad_correct()
                                             {bhu-1,0},{bhu-1,bwu/2},{bhu-1,bwu-1}};
             for (col = 0; col < bw; col++) {
                 for (i = 0; i < 9; i++) {
-                    ushort dist = (ushort)sqrt(abs(corners[i][0] - row) * abs(corners[i][0] - row) + abs(corners[i][1] - col) * abs(corners[i][1] - col));
+                    ushort dist = (ushort)sqrt(std::fabs(corners[i][0] - row) * std::fabs(corners[i][0] - row) + std::fabs(corners[i][1] - col) * std::fabs(corners[i][1] - col));
                     ushort weight = dist > maxdist ? 0 : maxdist - dist;
                     corners_weight[9*(row*bw+col)+i] = weight;
                 }
