--- wse_sdrxx.c.orig	2014-11-04 10:25:00 UTC
+++ wse_sdrxx.c
@@ -219,9 +219,9 @@ if(ui.rx_addev_no == RTL2832_DEVICE_CODE
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
@@ -265,9 +265,9 @@ if(ui.rx_addev_no == MIRISDR_DEVICE_CODE
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
