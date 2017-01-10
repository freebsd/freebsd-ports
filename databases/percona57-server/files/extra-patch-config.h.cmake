--- Makefile
+++ Makefile
@@ -95,8 +95,8 @@ post-patch:
 
 .include <bsd.port.pre.mk>
 
-.if ${ARCH} == "arm"
-BROKEN=		Does not compile on arm
+.if ${ARCH} == "armv6"   
+EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config.h.cmake
 .endif
 
 .include <bsd.port.post.mk>

--- /dev/null
+++ files/extra-patch-config.h.cmake
@@ -0,0 +1,12 @@
+--- config.h.cmake.orig	2014-12-05 16:24:02 UTC
++++ config.h.cmake
+@@ -151,7 +151,8 @@
+ #cmakedefine HAVE_FESETROUND 1
+ #cmakedefine HAVE_FINITE 1
+ #cmakedefine HAVE_FP_EXCEPT 1
+-#cmakedefine HAVE_FPSETMASK 1
++#cmakedefine HAVE_FPSETMASK 0
++#cmakedefine HAVE_FEDISABLEEXCEPT 1
+ #cmakedefine HAVE_FSEEKO 1
+ #cmakedefine HAVE_FSYNC 1
+ #cmakedefine HAVE_FTIME 1
