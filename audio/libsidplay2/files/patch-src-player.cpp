--- src/player.cpp.orig	Mon May  7 17:09:39 2001
+++ src/player.cpp	Sun Oct  6 20:53:45 2002
@@ -580,34 +580,49 @@
 int player::loadFilter (const sid_fc_t *cutoffs, uint_least16_t points)
 {
 #ifndef HAVE_HARDSID
-    fc_point fc[0x800];
- 
-    // Make sure there are enough filter points and they are legal
-    if ((points < 2) || (points > 0x800))
-        goto player_loadFilter_error;
+    fc_point fc[0x802];
+    const fc_point *f0 = fc;
+    int   pnts = 0;
 
+    if (cutoffs == NULL)
+    {   // Select default filter
+        sid.fc_default  (f0, pnts);
+        sid2.fc_default (f0, pnts);
+    }
+    else
     {
-        const sid_fc_t *val, *valp, vals = {-1, 0};
-        // Last check, make sure they are list in numerical order
-        // for both axis
-        val = &vals; // (start)
-        for (int i = 0; i < points; i++)
+        pnts = points;
+        // Make sure there are enough filter points and they are legal
+        if ((pnts < 2) || (pnts > 0x800))
+            goto player_loadFilter_error;
+
         {
-            valp = val;
-            val  = &cutoffs[i];
-            if ((*valp)[0] >  (*val)[0])
-                goto player_loadFilter_error;
-//            if ((*valp)[1] >= (*val)[1])
-//                goto player_loadFilter_error;
-            fc[i][0] = (sound_sample) (*val)[0];
-            fc[i][1] = (sound_sample) (*val)[1];
+            const sid_fc_t  fstart = {-1, 0};
+            const sid_fc_t *fprev  = &fstart, *fin = cutoffs;
+            fc_point *fout = fc;
+            // Last check, make sure they are list in numerical order
+            // for both axis
+            while (pnts-- > 0)
+            {
+                if ((*fprev)[0] >= (*fin)[0])
+                    goto player_loadFilter_error;
+                fout++;
+                (*fout)[0] = (sound_sample) (*fin)[0];
+                (*fout)[1] = (sound_sample) (*fin)[1];
+                fprev      = fin++;
+            }
+            // Updated ReSID interpolate requires we
+            // repeat the end pnts
+            *(fout+1) = *fout;
+            fc[0]     = fc[1];
+            pnts      = points + 2;
         }
     }
 
     // function from reSID
-    points--;
-    interpolate (fc, fc, fc + points, fc + points, sid.fc_plotter (), 1.0);
-    interpolate (fc, fc, fc + points, fc + points, sid2.fc_plotter(), 1.0);
+    pnts--;
+    interpolate (f0, f0 + pnts, sid.fc_plotter  (), 1.0);
+    interpolate (f0, f0 + pnts, sid2.fc_plotter (), 1.0);
 return 0;
 
 player_loadFilter_error:
