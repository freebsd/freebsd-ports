--- make/unix_gcc.mk.orig	Fri Jul 28 20:54:11 2000
+++ make/unix_gcc.mk	Fri Jan 26 07:05:06 2001
@@ -34,12 +34,20 @@
 GCCPATH=	/usr
 GCC=		cc
+ifneq "${freebsd}" "34"
 ifneq "${freebsd}" "40"
+ifneq "${freebsd}" "41"
+ifneq "${freebsd}" "42"
+ifneq "${freebsd}" "43"
 ifneq "${freebsd}" "50"
 GCCBASE=	/usr/local
 GCCTARGET=	i386-unknown-freebsd3.0
 GCCVER=		egcs-2.91.62
 GCCPATH=	${GCCBASE}/lib/gcc-lib/${GCCTARGET}/${GCCVER}
 GCC=		egcc
 endif
+endif
+endif
+endif
 endif
+endif
 endif
