--- libdjvu/MMX.cpp.orig	Fri Oct  1 14:42:33 2004
+++ libdjvu/MMX.cpp	Sat Nov  8 04:08:22 2003
@@ -161,7 +161,7 @@
 		    "1:\tpopl %%ebx\n\t"
                     "movl %%edx, %0"
                     : "=m" (cpuflags) :
-                    : "eax","ebx","ecx","edx");
+                    : "eax","ecx","edx");
 #endif
 #if defined(MMX) && defined(_MSC_VER) && defined(_M_IX86)
   // Detection of MMX for MSVC
