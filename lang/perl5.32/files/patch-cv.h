--- cv.h.orig	2020-12-18 10:04:36 UTC
+++ cv.h
@@ -78,14 +78,14 @@ See L<perlguts/Autoloading with XSUBs>.
 #define CvHSCXT(sv)	  *(assert_(CvISXSUB((CV*)(sv))) \
 	&(((XPVCV*)MUTABLE_PTR(SvANY(sv)))->xcv_padlist_u.xcv_hscxt))
 #ifdef DEBUGGING
-#  if PTRSIZE == 8
+#  if PTRADDRSIZE == 8
 #    define PoisonPADLIST(sv) \
         (((XPVCV*)MUTABLE_PTR(SvANY(sv)))->xcv_padlist_u.xcv_padlist = (PADLIST *)UINT64_C(0xEFEFEFEFEFEFEFEF))
-#  elif PTRSIZE == 4
+#  elif PTRADDRSIZE == 4
 #    define PoisonPADLIST(sv) \
         (((XPVCV*)MUTABLE_PTR(SvANY(sv)))->xcv_padlist_u.xcv_padlist = (PADLIST *)0xEFEFEFEF)
 #  else
-#    error unknown pointer size
+#    error unknown address size
 #  endif
 #else
 #  define PoisonPADLIST(sv) NOOP
