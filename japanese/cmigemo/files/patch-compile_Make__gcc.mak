--- compile/Make_gcc.mak.orig	2022-06-23 01:52:51 UTC
+++ compile/Make_gcc.mak
@@ -44,4 +44,7 @@ dictionary:
 	$(RM) $(libdir)/$(libmigemo)
 
 dictionary:
-	cd dict && $(MAKE) gcc
+	cd dict && $(MAKE) gcc-dict
+
+dat:
+	cd dict && $(MAKE) gcc-dat
