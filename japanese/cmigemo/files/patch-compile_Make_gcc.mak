--- compile/Make_gcc.mak.orig	2011-08-17 00:54:29.000000000 +0900
+++ compile/Make_gcc.mak	2011-08-17 00:56:14.000000000 +0900
@@ -44,4 +44,7 @@
 	$(RM) $(libdir)/$(libmigemo)
 
 dictionary:
-	cd dict && $(MAKE) gcc
+	cd dict && $(MAKE) gcc-dict
+
+dat:
+	cd dict && $(MAKE) gcc-dat
