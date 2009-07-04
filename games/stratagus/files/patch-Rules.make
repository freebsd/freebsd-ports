--- Rules.make.in.orig	2006-11-27 06:27:04.000000000 +0900
+++ Rules.make.in	2009-06-01 03:49:13.000000000 +0900
@@ -17,7 +17,7 @@
 # Prefix for 'make install'
 PREFIX=@PREFIX@
 
-CPPFLAGS=@DEFS@ @CPPFLAGS@ -DUSE_ZLIB -I$(TOPDIR) -I$(TOPDIR)/src/include -I$(TOPDIR)/src/guichan/include
+CPPFLAGS=-DUSE_ZLIB -I$(TOPDIR) -I$(TOPDIR)/src/include -I$(TOPDIR)/src/guichan/include @DEFS@ @CPPFLAGS@
 CXXFLAGS=@CXXFLAGS@
 LDFLAGS=@LDFLAGS@ -lpng -lz -lm
 
