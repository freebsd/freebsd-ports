Issutracker : #i41144#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description :
in odk project, machine type is determined by config.guess,
for FreeBSD, it returns freebsd5.3 or freebsd4.11 etc.
and adding missing things.

Index: odk/settings/settings.mk
===================================================================
RCS file: /cvs/api/odk/settings/settings.mk,v
retrieving revision 1.14
diff -u -r1.14 settings.mk
--- odk/settings/settings.mk	29 Mar 2005 12:19:26 -0000	1.14
+++ odk/settings/settings.mk	15 May 2005 13:54:38 -0000
@@ -397,7 +397,7 @@
 # FreeBSD specific settings
 #
 ###########################################################################
-ifeq "$(PLATFORM)" "freebsd"
+ifneq (,$(findstring freebsd,$(PLATFORM)))
 # Settings for FreeBSD using gcc compiler
 
 PROCTYPE := $(shell $(PRJ)/config.guess | cut -d"-" -f1)
@@ -435,6 +435,7 @@
 CSEP=\>
 QUOTE=$(subst S,\,S)
 QM=\"
+SQM='
 ECHOLINE=@echo
 P2BG=&
 
@@ -446,10 +447,10 @@
 # Include UDK version numbers
 include $(PRJ)/include/udkversion.mk
 
-SALLIB=-lsal
-CPPULIB=-lcppu
-CPPUHELPERLIB=-lcppuhelper$(COMID)
-SALHELPERLIB=-lsalhelper$(COMID)
+SALLIB=-luno_sal
+CPPULIB=-luno_cppu
+CPPUHELPERLIB=-luno_cppuhelper$(COMID)
+SALHELPERLIB=-luno_salhelper$(COMID)
 REGLIB=-lreg
 STORELIB=-lstore
 STLPORTLIB=-lstlport_gcc
