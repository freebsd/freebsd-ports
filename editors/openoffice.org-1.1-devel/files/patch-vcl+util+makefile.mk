Issutracker : #iXXXXX#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : another ENABLE_PASF issue, somehow strange though,
only FreeBSD 4.11-RELEASE needs this patch(?)

Index: vcl/util/makefile.mk
===================================================================
RCS file: /cvs/gsl/vcl/util/makefile.mk,v
retrieving revision 1.47.10.5
diff -u -r1.47.10.5 makefile.mk
--- vcl/util/makefile.mk	29 Apr 2005 14:28:18 -0000	1.47.10.5
+++ vcl/util/makefile.mk	13 May 2005 08:51:12 -0000
@@ -310,7 +310,7 @@
 .ENDIF          # "$(OS)"=="SOLARIS"
 .ENDIF          # "$(GUIBASE)"=="unx"
 
-.IF "$(ENABLE_PASF)" != ""
+.IF "$(ENABLE_PASF)" == "YES"
 .IF "$(OS)"=="MACOSX"
 SHL1STDLIBS += -framework CoreAudio -framework AudioToolbox
 .ENDIF
