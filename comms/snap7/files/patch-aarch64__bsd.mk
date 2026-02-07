--- aarch64_bsd.mk.orig	2021-07-21 15:55:09 UTC
+++ aarch64_bsd.mk
@@ -0,0 +1,12 @@
+##
+## aarch64 BSD based (FreeBSD etc.) Makefile
+## Use gmake instead of make
+##
+TargetCPU  :=aarch64
+OS         :=bsd
+CXXFLAGS   := -O3 -g -fPIC -pedantic
+
+# Standard part
+
+include common.mk
+
