--- ./testtools/source/bridgetest/makefile.mk.orig	2012-04-17 11:41:16.000000000 +0200
+++ ./testtools/source/bridgetest/makefile.mk	2012-04-17 11:41:53.000000000 +0200
@@ -56,6 +56,8 @@
 my_components += testComponent
 .END
 
+CFLAGSCXX += -fPIC
+
 .IF "$(GUI)"=="WNT"
 .IF "$(compcheck)" != ""
 CFLAGSCXX += -DCOMPCHECK
