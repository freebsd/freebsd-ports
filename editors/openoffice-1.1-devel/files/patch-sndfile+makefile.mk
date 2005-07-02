Issutracker : #iXXXXX#
CWS         : N/A
Author      : 
Description : 

--- sndfile/makefile.mk	Wed Jun  1 01:31:45 2005
+++ sndfile/makefile.mk	Fri Jul  1 09:17:49 2005
@@ -81,8 +81,12 @@
 CONFIGURE_DIR=
 
 CONFIGURE_ACTION=./configure --with-pic
-.IF "$(COM)" == "GCC" && "$(OS)" != "MACOSX" && "$(OS)" != "FREEBSD"
+.IF "$(COM)" == "GCC"
+.IF "$(OS)" != "MACOSX"
+.IF "$(OS)" != "FREEBSD"
 CONFIGURE_FLAGS=LDFLAGS=-Wl,-noinhibit-exec
+.ENDIF
+.ENDIF
 .ENDIF
 
 BUILD_DIR=$(CONFIGURE_DIR)
