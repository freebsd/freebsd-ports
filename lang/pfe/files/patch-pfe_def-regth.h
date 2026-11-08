--- pfe/def-regth.h.orig	2009-10-04 13:06:45 UTC
+++ pfe/def-regth.h
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
