--- sound.cc.orig	Fri May 25 23:13:55 2001
+++ sound.cc	Fri May 25 23:13:59 2001
@@ -423,7 +423,7 @@
     }
   }
      
-  data = new short[NumSamples*2];  
+  data = new u_short[NumSamples*2];  
   memset((char*)data,0,NumSamples*4);
 }
