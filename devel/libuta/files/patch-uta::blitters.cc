--- /usr/obj/mnt/files/freebsd-cvs/ports/devel/libuta/work/libuta-0.4.4/uta/blitters.cc.orig	Sat Oct 12 23:11:07 2002
+++ /usr/obj/mnt/files/freebsd-cvs/ports/devel/libuta/work/libuta-0.4.4/uta/blitters.cc	Thu Aug 12 20:58:40 2004
@@ -20,6 +20,7 @@
 
 #include "blitters.h"
 #include <painter.h>
+#include <cassert>
 
 namespace uta {
 
@@ -28,6 +29,8 @@
 #endif
 #if !defined(X86_ASSEMBLER)
 
+using namespace std;
+
 /** Apply const gamma value.
     Blit just copies alpha value of the source to the destination surface.
  */
@@ -163,7 +166,7 @@
 		 only using the lower 16bits of result
 		 ... this is somehow dumb, but only executed once
 		 per scanline, so I do not care */
-	      movd_r2m(mm1,(unsigned int*)dPtr);
+	      movd_r2m(mm1,*(mmx_t*)dPtr);
 	      sPtr += 4;
 	      dPtr += 4;
 	    }
@@ -211,7 +214,7 @@
 		 only using the lower 16bits of result
 		 ... this is somehow dumb, but only executed once
 		 per scanline, so I do not care */
-	      movd_r2m(mm1,(unsigned int*)dPtr);
+	      movd_r2m(mm1,*(mmx_t*)dPtr);
 	      sPtr += 4;
 	      dPtr += 4;
 	    }
@@ -960,7 +963,7 @@
 	     only using the lower 16bits of result
 	     ... this is somehow dumb, but only executed once
 	     per scanline, so I do not care */
-	  movd_r2m(mm1,(unsigned int*)dPtr);
+	  movd_r2m(mm1,*(mmx_t*)dPtr);
 	  sPtr += 4;
 	  dPtr += 4;
 	}
