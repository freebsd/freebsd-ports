--- compile/Make_gcc.mak.orig	2014-12-20 04:39:02 UTC
+++ compile/Make_gcc.mak
@@ -44,4 +44,7 @@ uninstall-lib:
 	$(RM) $(libdir)/$(libmigemo)
 
 dictionary:
-	cd dict && $(MAKE) gcc
+	cd dict && $(MAKE) gcc-dict
+
+dat:
+	cd dict && $(MAKE) gcc-dat
