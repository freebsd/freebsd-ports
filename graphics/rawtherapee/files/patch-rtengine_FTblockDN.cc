This is a manual combination (otherwise patch would mess up)
of the two pathes mentioned below:

= PATCH 1 GIT HEADER ============================
From 5239e61946870a5405e94b138b4196fc35159ab1 Mon Sep 17 00:00:00 2001
From: Ingo Weyrich <heckflosse@users.noreply.github.com>
Date: Fri, 12 Jun 2020 12:57:52 +0200
Subject: [PATCH] Fix segfault in denoise, fixes #5796

---
 rtengine/FTblockDN.cc | 9 ++-------
 1 file changed, 2 insertions(+), 7 deletions(-)

diff --git a/rtengine/FTblockDN.cc b/rtengine/FTblockDN.cc
index 89e4c1b8d..49b566767 100644

= PATCH 2 GIT HEADER ============================
From 6c1055f985a202e1b1a87f8d33b482748f41a167 Mon Sep 17 00:00:00 2001
From: Ingo Weyrich <heckflosse@users.noreply.github.com>
Date: Fri, 12 Jun 2020 13:02:37 +0200
Subject: [PATCH] Fix another segfault in denoise

---
 rtengine/FTblockDN.cc | 9 ++-------
 1 file changed, 2 insertions(+), 7 deletions(-)

diff --git a/rtengine/FTblockDN.cc b/rtengine/FTblockDN.cc
index 49b566767..0146f0a7d 100644

==== MERGED PATCHES =============================
diff -up ./rtengine/FTblockDN.cc.orig ./rtengine/FTblockDN.cc
--- ./rtengine/FTblockDN.cc.orig	2020-02-04 07:39:52.000000000 +0100
+++ ./rtengine/FTblockDN.cc	2020-06-14 17:14:55.390169000 +0200
@@ -957,13 +957,8 @@ BENCHFUN
                                         labdn->b[i1][j1] = B_ < 65535.f ? gamcurve[B_] : Color::gammanf(B_ / 65535.f, gam) * 32768.f;
 
                                         if (((i1 | j1) & 1) == 0) {
-                                            if (numTries == 1) {
-                                                noisevarlum[(i1 >> 1) * width2 + (j1 >> 1)] = useNoiseLCurve ? lumcalc[i >> 1][j >> 1] : noisevarL;
-                                                noisevarchrom[(i1 >> 1) * width2 + (j1 >> 1)] = useNoiseCCurve ? maxNoiseVarab * ccalc[i >> 1][j >> 1] : 1.f;
-                                            } else {
-                                                noisevarlum[(i1 >> 1) * width2 + (j1 >> 1)] = lumcalc[i >> 1][j >> 1];
-                                                noisevarchrom[(i1 >> 1) * width2 + (j1 >> 1)] = ccalc[i >> 1][j >> 1];
-                                            }
+                                            noisevarlum[(i1 >> 1) * width2 + (j1 >> 1)] = useNoiseLCurve ? lumcalc[i >> 1][j >> 1] : noisevarL;
+                                            noisevarchrom[(i1 >> 1) * width2 + (j1 >> 1)] = useNoiseCCurve ? maxNoiseVarab * ccalc[i >> 1][j >> 1] : 1.f;
                                         }
 
                                         //end chroma
@@ -995,13 +990,8 @@ BENCHFUN
                                         labdn->b[i1][j1] = (Y - Z);
 
                                         if (((i1 | j1) & 1) == 0) {
-                                            if (numTries == 1) {
-                                                noisevarlum[(i1 >> 1)*width2 + (j1 >> 1)] = useNoiseLCurve ? lumcalc[i >> 1][j >> 1] : noisevarL;
-                                                noisevarchrom[(i1 >> 1)*width2 + (j1 >> 1)] = useNoiseCCurve ? maxNoiseVarab * ccalc[i >> 1][j >> 1] : 1.f;
-                                            } else {
-                                                noisevarlum[(i1 >> 1)*width2 + (j1 >> 1)] = lumcalc[i >> 1][j >> 1];
-                                                noisevarchrom[(i1 >> 1)*width2 + (j1 >> 1)] = ccalc[i >> 1][j >> 1];
-                                            }
+                                            noisevarlum[(i1 >> 1)*width2 + (j1 >> 1)] = useNoiseLCurve ? lumcalc[i >> 1][j >> 1] : noisevarL;
+                                            noisevarchrom[(i1 >> 1)*width2 + (j1 >> 1)] = useNoiseCCurve ? maxNoiseVarab * ccalc[i >> 1][j >> 1] : 1.f;
                                         }
                                     }
                                 }
