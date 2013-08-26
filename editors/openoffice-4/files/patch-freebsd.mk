--- solenv/gbuild/platform/freebsd.mk	2012-10-31 10:39:44.000000000 +0900
+++ solenv/gbuild/platform/freebsd.mk	2012-10-31 17:40:48.000000000 +0900
@@ -121,6 +121,7 @@
 	-Wl,-z,combreloc \
 	-Wl,-z,defs \
 	$(subst -L../lib , ,$(SOLARLIB)) \
+	%%RPATH%% \
 	 \
 
 ifeq ($(HAVE_LD_HASH_STYLE),TRUE)
