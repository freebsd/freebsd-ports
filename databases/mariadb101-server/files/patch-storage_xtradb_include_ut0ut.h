--- storage/xtradb/include/ut0ut.h.orig	2019-10-08 20:51:54 UTC
+++ storage/xtradb/include/ut0ut.h
@@ -83,7 +83,7 @@ struct ut_when_dtor { (private)
    the YieldProcessor macro defined in WinNT.h. It is a CPU architecture-
    independent way by using YieldProcessor. */
 #  define UT_RELAX_CPU() YieldProcessor()
-# elif defined(__powerpc__)
+# elif defined(__powerpc__) && defined __GLIBC__
 #include <sys/platform/ppc.h>
 #  define UT_RELAX_CPU() __ppc_get_timebase()
 # else
