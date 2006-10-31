--- src/Makefile.mk.orig	Thu Sep 28 18:05:30 2006
+++ src/Makefile.mk	Thu Sep 28 18:05:41 2006
@@ -44,7 +44,6 @@
 
 # Generic compile/link flags
 #	Suitable for plain vanilla Unix but normally overridden.
-CC = cc
 CFLAGS = -c -I. -I$(SRC)
 CFLAGS_AUX =
 CFLAGS_LINT =
