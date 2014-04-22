--- plugins/zynaddsubfx/src/Effects/Alienwah.cpp.orig	2014-02-25 15:16:26.000000000 +0200
+++ plugins/zynaddsubfx/src/Effects/Alienwah.cpp	2014-02-25 15:17:00.000000000 +0200
@@ -67,7 +67,7 @@
         tmp = clfol * x + oldclfol * x1;
 
         out = tmp * oldl[oldk];
-        out.real() += (1 - fabs(fb)) * smp.l[i] * (1.0 - panning);
+        out += (1 - fabs(fb)) * smp.l[i] * (1.0 - panning);
 
         oldl[oldk]  = out;
         REALTYPE l = out.real() * 10.0 * (fb + 0.1);
@@ -76,7 +76,7 @@
         tmp = clfor * x + oldclfor * x1;
 
         out = tmp * oldr[oldk];
-        out.real() += (1 - fabs(fb)) * smp.r[i] * (1.0 - panning);
+        out += (1 - fabs(fb)) * smp.r[i] * (1.0 - panning);
 
         oldr[oldk]  = out;
         REALTYPE r = out.real() * 10.0 * (fb + 0.1);
