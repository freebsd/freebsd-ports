$FreeBSD$

--- ../ecos/host/tools/configtool/standalone/wxwin/makefile.gnu.orig	Wed May 14 14:20:15 2003
+++ ../ecos/host/tools/configtool/standalone/wxwin/makefile.gnu	Mon Nov 17 11:44:38 2003
@@ -6,23 +6,20 @@
 #   cd emptydir
 #   make -f /path/to/this/makefile WXDIR=/path/to/wx/installation INSTALLDIR=/path/to/ecos/tools [ ECOSSRCDIR=/path/to/ecos/tools/src ] [ TCLDIR=/path/to/tcl/installation ] [ DEBUG=1 ]
 
-INSTALLDIR=INSTALLDIR_not_defined
-WXDIR=WXDIR_not_defined
-
 CTBUILDDIR=$(shell pwd)
-ECOSSRCDIR=$(INSTALLDIR)/src
 CTDIR=$(ECOSSRCDIR)/tools/configtool/standalone/wxwin
-TCLDIR=TCLDIR_use_system
 USEEXPERIMENTALCODE=1
 
 EXTRACPPFLAGS=\
-  -I$(TCLDIR)/include \
   -I$(INSTALLDIR)/include \
+  -I$(INSTALLDIR)/include/tcl8.4 \
+  -I$(ECOSSRCDIR)/libcdl \
+  -I$(ECOSSRCDIR)/../../infra-build/infra \
   -I$(ECOSSRCDIR)/tools/configtool/common/common \
   -I$(ECOSSRCDIR)/tools/Utils/common \
   -I$(ECOSSRCDIR)/tools/ecostest/common \
   -DecUSE_EXPERIMENTAL_CODE=$(USEEXPERIMENTALCODE)
-EXTRALDFLAGS=-L$(TCLDIR)/lib -L$(INSTALLDIR)/lib -lcdl -lcyginfra -ltcl
+EXTRALDFLAGS=-L$(TCLDIR)/lib -L$(INSTALLDIR)/lib -L$(ECOSSRCDIR)/../../infra-build/libcdl -L$(ECOSSRCDIR)/../../infra-build/infra -lcdl -lcyginfra -ltcl84
 
 ifneq (,$(findstring CYGWIN, $(shell uname)))
   PROGRAM=configtool.exe
@@ -31,8 +28,8 @@
   EXTRAOBJECTS=$(CTBUILDDIR)/configtoolres.o
 else
   PROGRAM=configtool
-  CPPFLAGS=`$(WXDIR)/bin/wx-config --cppflags`
-  LDFLAGS=`$(WXDIR)/bin/wx-config --libs`
+  CPPFLAGS=`$(WXDIR)/bin/$(WX_CONFIG) --cppflags`
+  LDFLAGS=`$(WXDIR)/bin/$(WX_CONFIG) --libs`
   EXTRAOBJECTS=
 endif
 
