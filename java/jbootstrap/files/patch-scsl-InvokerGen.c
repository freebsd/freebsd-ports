$FreeBSD$

--- scsl/InvokerGen.c.orig	Fri Aug 19 11:04:45 2005
+++ scsl/InvokerGen.c	Fri Aug 19 11:04:03 2005
@@ -475,7 +475,8 @@
                                        ", of sig='", si->sig, "'");
         }
     }
     t[j] = 0;
+    sb[pos] = NUL;
     si->returnType = t[--j];
     si->binTerse = t;
     si->terse = sb;
