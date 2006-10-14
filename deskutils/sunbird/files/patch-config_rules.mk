--- config/rules.mk.orig	Fri Jul  7 00:13:36 2006
+++ config/rules.mk	Sun Sep  3 00:04:03 2006
@@ -443,7 +443,7 @@
 
 ifeq ($(OS_ARCH),FreeBSD)
 ifdef IS_COMPONENT
-EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic
+EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic -lc
 endif
 endif
 
