--- lmain.c.orig	Sat May 27 07:48:22 2006
+++ lmain.c	Sat Jun 17 23:49:10 2006
@@ -11,7 +11,6 @@
 #define MAX_MOUSE_CURSIZE 50
 
 
-#include <sys/io.h>
 #include <vga.h>
 #include <vgagl.h>
 #include <vgamouse.h>
@@ -97,6 +96,7 @@
 simd1=0;
 mmx_present=i&1;
 if(mmx_present != 0)simd_present=i/2; else simd_present=0;
+#if 0
 if(i!=0)
   {
   file = fopen("/proc/cpuinfo", "r");
@@ -142,9 +142,11 @@
     file=NULL;
     }
   }  
+#endif
 file = fopen(userint_filename, "rb");
 if (file == NULL)
   {
+#if 0
   if(xxprint != 0)
     {
     i=0;
@@ -170,6 +172,7 @@
       printf("\nwith appropriate patches.\n\n");
       }
     }
+#endif
   printf("\nSetup file %s missing.",userint_filename);
 full_setup:;
   for(i=0; i<MAX_UIPARM; i++) uiparm[i]=0;
