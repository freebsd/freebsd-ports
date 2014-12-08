--- wse_sdrxx.c.orig	2014-11-04 02:25:00.000000000 -0800
+++ wse_sdrxx.c	2014-12-08 03:15:31.000000000 -0800
@@ -219,9 +219,9 @@
     m=10000;
     for(i=0; i<no_of_rtl2832_gains; i++)
       {
-      if(fabs(fg.gain-(int)rint(0.1*rtl2832_gains[i])) < m)
+      if(abs(fg.gain-(int)rint(0.1*rtl2832_gains[i])) < m)
         {
-        m=fabs(fg.gain-(int)rint(0.1*rtl2832_gains[i]));
+        m=abs(fg.gain-(int)rint(0.1*rtl2832_gains[i]));
         j=i;
         }
       }
@@ -265,9 +265,9 @@
     m=10000;
     for(i=0; i<no_of_mirics_gains; i++)
       {
-      if(fabs(fg.gain-mirics_gains[i]) < m)
+      if(abs(fg.gain-mirics_gains[i]) < m)
         {
-        m=fabs(fg.gain-mirics_gains[i]);
+        m=abs(fg.gain-mirics_gains[i]);
         j=i;
         }
       }
