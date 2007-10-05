--- biewlib/sysdep/ia16/cmn_ix86.c.orig	2003-03-27 07:19:30.000000000 +0100
+++ biewlib/sysdep/ia16/cmn_ix86.c	2007-10-04 15:24:45.000000000 +0200
@@ -47,7 +47,7 @@
   ctrl_arr = c_arr;
   /* align pointer on 16-byte boundary */
 
-  if((tUInt32)ctrl_arr & 15) ((tUInt32)ctrl_arr) += 16-((tUInt32)ctrl_arr&15);
+  if((tUInt32)ctrl_arr & 15) ctrl_arr = ((tUInt32)ctrl_arr) + 16-((tUInt32)ctrl_arr&15);
 
   memset(ctrl_arr,0,sizeof(ctrl_arr));
   if(time_interval)
