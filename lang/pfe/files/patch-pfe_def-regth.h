--- pfe/def-regth.h.orig	2015-03-31 14:23:33.000000000 +0200
+++ pfe/def-regth.h	2015-03-31 14:23:30.000000000 +0200
@@ -40,11 +40,7 @@ struct p4_Session;
 # endif
 
 # ifdef PFE_USE_THREAD_POINTER
-#  ifdef P4_REGTH
-register struct p4_Thread* p4TH asm (P4_REGTH);
-#  else
 extern PFE_CC_THREADED struct p4_Thread* p4TH;
-#  endif
 # else
 # define p4TH (&p4_reg)
 extern PFE_CC_THREADED struct p4_Thread  p4_reg;
