--- make/unix_gcc.mk.orig	Fri Jul 28 11:54:11 2000
+++ make/unix_gcc.mk	Mon Mar 18 07:29:27 2002
@@ -33,13 +33,25 @@
 ifdef freebsd
 GCCPATH=	/usr
 GCC=		cc
+ifneq "${freebsd}" "34"
 ifneq "${freebsd}" "40"
+ifneq "${freebsd}" "41"
+ifneq "${freebsd}" "42"
+ifneq "${freebsd}" "43"
+ifneq "${freebsd}" "44"
+ifneq "${freebsd}" "45"
 ifneq "${freebsd}" "50"
 GCCBASE=	/usr/local
 GCCTARGET=	i386-unknown-freebsd3.0
 GCCVER=		egcs-2.91.62
 GCCPATH=	${GCCBASE}/lib/gcc-lib/${GCCTARGET}/${GCCVER}
 GCC=		egcc
+endif
+endif
+endif
+endif
+endif
+endif
 endif
 endif
 endif
