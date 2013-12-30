--- mk/re.mk.orig	2013-12-20 13:16:19.461335812 +0000
+++ mk/re.mk	2013-12-20 13:16:30.914336263 +0000
@@ -73,9 +73,6 @@
 ifeq ($(CC),)
 	CC := gcc
 endif
-ifeq ($(CC),cc)
-	CC := gcc
-endif
 LD := $(CC)
 CC_LONGVER := $(shell if $(CC) -v 2>/dev/null; then \
 						$(CC) -v 2>&1 ;\
