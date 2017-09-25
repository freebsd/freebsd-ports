--- src/recompiler/tcg/i386/tcg-target.h.orig	2017-09-13 09:34:48 UTC
+++ src/recompiler/tcg/i386/tcg-target.h
@@ -120,12 +120,20 @@ enum {
 
 /* Note: must be synced with dyngen-exec.h */
 #if TCG_TARGET_REG_BITS == 64
+# ifndef __clang__
 # define TCG_AREG0 TCG_REG_R14
+# else  /* __clang__ */
+#  define TCG_AREG0 TCG_REG_RBP
+# endif /* __clang__ */
 #else
 # ifndef VBOX /* we're using ESI instead of EBP, probably due to frame pointer opt issues */
 # define TCG_AREG0 TCG_REG_EBP
 # else  /* VBOX */
+#  ifndef __clang__
 #  define TCG_AREG0 TCG_REG_ESI
+#  else  /* __clang__ */
+#   define TCG_AREG0 TCG_REG_EBP
+#  endif /* __clang__ */
 # endif /* VBOX */
 #endif
 
