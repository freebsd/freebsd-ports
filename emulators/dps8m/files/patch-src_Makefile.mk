--- src/Makefile.mk.orig	2021-12-07 20:32:53 UTC
+++ src/Makefile.mk
@@ -163,7 +163,7 @@ endif
 # Default FLAGS
 
 ifndef SUNPRO
-  CFLAGS  += -Wall -g3 -O3 -fno-strict-aliasing
+  CFLAGS  += -Wall -fno-strict-aliasing
 endif
 CFLAGS  += $(X_FLAGS)
 LDFLAGS += $(X_FLAGS)
