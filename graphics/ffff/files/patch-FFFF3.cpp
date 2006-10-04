--- ./FFFF3.cpp.orig	Wed Oct  4 11:21:15 2006
+++ ./FFFF3.cpp	Wed Oct  4 11:21:35 2006
@@ -24,6 +24,7 @@
 ... and all the others who kindly sent code, fixes, suggestions and feedback !
 *******************************************************************/
 
+int get_nprocs() {return 1;}
 
 // WARNING: This source is a real mess ! :)))
 // WARNING: This is only meant as some "portable" glue for assembly.
@@ -70,7 +71,7 @@
   #include <sys/select.h>
   #include <sys/types.h>
   #include <sys/sysctl.h>
-  #include <sys/sysinfo.h>
+//  #include <sys/sysinfo.h>
 #else
   #include "GL/glut.h"
   #include "GL/gl.h"
@@ -381,7 +382,8 @@
 	}
 #endif
  
-  avail_SSE = checkSSE();
+  //avail_SSE = checkSSE();
+  avail_SSE = 1;
   if (avail_SSE)  {
 #if defined(__APPLE__) && __BIG_ENDIAN__
     // PowerPC
@@ -397,7 +399,8 @@
     printf("Switching to machine code FPU mode.\n");
   }
 
-  avail_SSE2 = checkSSE2();
+  //avail_SSE2 = checkSSE2();
+  avail_SSE2 = 1;
   if (avail_SSE2)  {
 #if defined (sgi)
     printf("MIPS dual FPU units supported.\n");
