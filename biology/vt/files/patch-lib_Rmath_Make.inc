--- lib/Rmath/Make.inc.orig	2020-06-04 16:21:07 UTC
+++ lib/Rmath/Make.inc
@@ -3,21 +3,21 @@
 OS = $(shell uname)
 ARCH = $(shell uname -m)
 
-FC = gfortran
-FFLAGS-add += -O3
+FC ?= gfortran
+# FFLAGS-add += -O3
 
-USEGCC = 1
-USECLANG = 0
+USEGCC = 0
+USECLANG = 1
 
-CFLAGS-add += -Wall -O3
+# CFLAGS-add += -Wall -O3
 
 ifeq ($(USECLANG),1)
 USEGCC = 0
-CC = clang
+CC ?= clang
 endif
 
 ifeq ($(USEGCC),1)
-CC = gcc
+CC ?= gcc
 endif
 AR = ar
 
