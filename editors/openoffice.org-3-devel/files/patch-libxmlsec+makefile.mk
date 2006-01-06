Issuetracker : #i56954#
CWS          : N/A
Author       : <maho@openoffice.org> (JCA)
Description  : FreeBSD porting : Passing $ORIGIN to linker at libxmlsec project
We also want to pass -rpath $ORIGIN to linker as GNU/Linux and/or Solaris's case.

Index: libxmlsec/makefile.mk
===================================================================
RCS file: /cvs/external/libxmlsec/makefile.mk,v
retrieving revision 1.7
diff -u -r1.7 makefile.mk
--- libxmlsec/makefile.mk	28 Dec 2005 16:58:06 -0000	1.7
+++ libxmlsec/makefile.mk	5 Jan 2006 12:34:24 -0000
@@ -98,6 +98,9 @@
 .IF "$(OS)$(COM)"=="SOLARISC52"
 xmlsec_LDFLAGS+=-Wl,-R'$$$$ORIGIN'
 .ENDIF			# "$(OS)$(COM)"=="SOLARISC52"
+.IF "$(OS)$(COM)"=="FREEBSDGCC"
+LDFLAGS:=-Wl,-rpath,'$$$$ORIGIN'
+.ENDIF			# "$(OS)$(COM)"=="FREEBSDGCC"
 LDFLAGS:=$(xmlsec_LDFLAGS)
 .EXPORT: LDFLAGS
 
