Issutracker : #i49683#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : -noinhibit-exec allows linking against non-existent libs

Index: sndfile/makefile.mk
===================================================================
RCS file: /cvs/external/sndfile/makefile.mk,v
retrieving revision 1.5
diff -u -r1.5 makefile.mk
--- sndfile/makefile.mk	30 Mar 2005 08:52:06 -0000	1.5
+++ sndfile/makefile.mk	5 Apr 2005 01:23:46 -0000
@@ -81,7 +81,7 @@
 CONFIGURE_DIR=
 
 CONFIGURE_ACTION=./configure --with-pic
-.IF "$(COM)" == "GCC" && "$(OS)" != "MACOSX"
+.IF "$(COM)" == "GCC" && "$(OS)" != "MACOSX" && "$(OS)" != "FREEBSD"
 CONFIGURE_FLAGS=LDFLAGS=-Wl,-noinhibit-exec
 .ENDIF
 
