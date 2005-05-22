Issutracker : #i49685#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : Update to recent version of unxlngi6.mk
($Revision: 1.12 and $Author: obo $ $Date: 2005/05/06 09:37:55 $)

Index: solenv/inc/unxfbsdi.mk
===================================================================
RCS file: /cvs/tools/solenv/inc/unxfbsdi.mk,v
retrieving revision 1.13
diff -u -r1.13 unxfbsdi.mk
--- solenv/inc/unxfbsdi.mk	11 Feb 2005 15:27:55 -0000	1.13
+++ solenv/inc/unxfbsdi.mk	15 May 2005 04:51:41 -0000
@@ -99,9 +99,6 @@
 CC+:=$(CFLAGS_SYSBASE)
 .ENDIF          # "$(SYSBASE)"!=""
 CFLAGS+=-Wreturn-type -fmessage-length=0 -c $(INCLUDE)
-.IF "$(PRODUCT)"!=""
-CFLAGS+=-Wuninitialized
-.ENDIF
 
 # flags to enable build with symbols; required for crashdump feature
 .IF "$(ENABLE_SYMBOLS)"=="SMALL"
@@ -122,6 +119,9 @@
 CFLAGSCXX= -pipe -mtune=pentiumpro
 CFLAGSCXX+= -Wno-ctor-dtor-privacy
 PICSWITCH:=-fpic
+.IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
+CFLAGSCXX += -fvisibility-inlines-hidden
+.ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 
 # Compiler flags for compiling static object in single threaded environment with graphical user interface
 CFLAGSOBJGUIST=
@@ -143,6 +143,7 @@
 # Compiler flags for enabling optimazations
 .IF "$(PRODUCT)"!=""
 CFLAGSOPT=-Os -fno-strict-aliasing		# optimizing for products
+CFLAGSOPT+=-Wuninitialized				# not supported without optimization
 .ELSE 	# "$(PRODUCT)"!=""
 CFLAGSOPT=   							# no optimizing for non products
 .ENDIF	# "$(PRODUCT)"!=""
@@ -161,11 +162,12 @@
 
 # name of linker
 LINK*=$(CXX)
+LINKC*=$(CC)
 
 # default linker flags
 LINKFLAGSDEFS*=#-Wl,-z,defs
 LINKFLAGSRUNPATH*=-Wl,-rpath,\''$$ORIGIN'\'
-LINKFLAGS=-z combreloc $(LINKFLAGSDEFS) $(LINKFLAGSRUNPATH)
+LINKFLAGS=-Wl,-z,combreloc $(LINKFLAGSDEFS) $(LINKFLAGSRUNPATH)
 
 # linker flags for linking applications
 LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec
@@ -237,3 +239,4 @@
 DLLPOSTFIX=fi
 DLLPRE=lib
 DLLPOST=.so
+
