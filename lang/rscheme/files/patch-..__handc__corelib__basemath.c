
$FreeBSD: /tmp/pcvs/ports/lang/rscheme/files/patch-..__handc__corelib__basemath.c,v 1.1 2006-04-20 21:32:20 anray Exp $

--- ../handc/runtime/basemath.c	Fri Feb 10 14:51:07 2006
+++ ../handc/runtime/basemath.c	Fri Feb 10 14:57:02 2006
@@ -1319,6 +1319,7 @@
   } else {
     scheme_error( "non-basic-integer value ~s is not a valid UINT_32", 1, a );
   }
+  return 0;
 }
 
 /* extra 1 (36+1=37) is for NUL which isn't used... */
