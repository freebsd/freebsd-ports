--- modesub.c.orig	Tue May 18 09:43:30 2004
+++ modesub.c	Fri Jul  9 11:17:15 2004
@@ -5,7 +5,7 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <sys/mman.h>
-#include <sys/io.h>
+#include <machine/cpufunc.h>
 #include "globdef.h"
 #include "uidef.h"
 #include "fft1def.h"
@@ -1068,6 +1068,7 @@
     j++;
     if(j > 1000)
       {
+#if 0
       if(mlockall(MCL_CURRENT) != 0)
         {
         handle[0]=(int)(chk_free(testbuf));
@@ -1075,6 +1076,7 @@
         return 0;
         }
       j=0;
+#endif
       }  
     }  
   }
@@ -1597,7 +1599,9 @@
 idle_start=recent_time;
 if(ui.memlock == 0)
   {
+#if 0
   if(mlockall(MCL_CURRENT) != 0)lir_status=LIR_MEMERR;
+#endif
   }
 work_flag=0;
 
