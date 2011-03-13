--- mk/Variables.mk.orig	2011-03-13 13:59:37.000000000 +0100
+++ mk/Variables.mk	2011-03-13 13:59:47.000000000 +0100
@@ -3,8 +3,8 @@
 # PREFIX, EPREFIX, prefix and exec_prefix. Lower cases variants have higher
 # priority.
 #
-PREFIX		:= $(prefix)
-PREFIX		:= /usr/local
+PREFIX		?= $(prefix)
+PREFIX		?= /usr/local
 EPREFIX		:= $(exec_prefix)
 EPREFIX		:= $(PREFIX)
 prefix		:= $(PREFIX)
