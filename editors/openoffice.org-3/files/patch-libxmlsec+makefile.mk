Issuetracker : #i56954#
CWS          : N/A
Author       : <maho@openoffice.org> (JCA)
Description  : FreeBSD porting : Passing $ORIGIN to linker at libxmlsec project
We also want to pass -rpath $ORIGIN to linker as GNU/Linux and/or Solaris's case.

--- libxmlsec/makefile.mk.org	Tue Oct 25 15:00:10 2005
+++ libxmlsec/makefile.mk	Tue Oct 25 15:00:28 2005
@@ -89,6 +89,9 @@
 .IF "$(OS)$(COM)"=="SOLARISC52"
 LDFLAGS:=-Wl,-R'$$$$ORIGIN'
 .ENDIF			# "$(OS)$(COM)"=="SOLARISC52"
+.IF "$(OS)$(COM)"=="FREEBSDGCC"
+LDFLAGS:=-Wl,-rpath,'$$$$ORIGIN'
+.ENDIF			# "$(OS)$(COM)"=="FREEBSDGCC"
 .EXPORT: LDFLAGS
 .ENDIF
 CONFIGURE_DIR=
