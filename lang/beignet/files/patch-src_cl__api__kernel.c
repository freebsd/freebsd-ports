--- src/cl_api_kernel.c.orig	2017-01-20 10:40:51 UTC
+++ src/cl_api_kernel.c
@@ -26,6 +26,7 @@
 #include "CL/cl.h"
 #include <stdio.h>
 #include <string.h>
+#include <sys/types.h>
 
 cl_int
 clGetKernelInfo(cl_kernel kernel,
