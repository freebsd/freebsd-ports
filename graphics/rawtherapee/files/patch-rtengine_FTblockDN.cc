From 5239e61946870a5405e94b138b4196fc35159ab1 Mon Sep 17 00:00:00 2001
From: Ingo Weyrich <heckflosse@users.noreply.github.com>
Date: Fri, 12 Jun 2020 12:57:52 +0200
Subject: [PATCH] Fix segfault in denoise, fixes #5796

--- rtengine/FTblockDN.cc.orig	2020-02-04 06:39:52 UTC
+++ rtengine/FTblockDN.cc
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
