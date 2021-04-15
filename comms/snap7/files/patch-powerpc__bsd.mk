--- powerpc_bsd.mk.orig	2016-12-20 10:44:15 UTC
+++ powerpc_bsd.mk
@@ -0,0 +1,12 @@
+##
+## powerpc BSD based (FreeBSD etc.) Makefile
+## Use gmake instead of make
+##
+TargetCPU  :=powerpc
+OS         :=bsd
+CXXFLAGS   := -O3 -fPIC -pedantic 
+
+# Standard part
+
+include common.mk
+
