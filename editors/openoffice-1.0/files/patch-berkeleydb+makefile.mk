--- berkeleydb/makefile.mk.orig	Sat Apr 12 14:45:40 2003
+++ berkeleydb/makefile.mk	Sat Apr 12 14:46:29 2003
@@ -84,7 +84,9 @@
 
 BUILD_DIR=$(CONFIGURE_DIR)
 BUILD_ACTION=make
+.IF "$(OS)"!="FREEBSD"
 BUILD_FLAGS=-j$(MAXPROCESS)
+.ENDIF
 
 OUT2LIB=$(BUILD_DIR)$/.libs$/libdb*.so
 
