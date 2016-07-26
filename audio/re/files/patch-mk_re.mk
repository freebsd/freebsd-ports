--- mk/re.mk.orig	2016-04-15 07:09:59 UTC
+++ mk/re.mk
@@ -75,9 +75,6 @@ endif
 ifeq ($(CC),)
 	CC := gcc
 endif
-ifeq ($(CC),cc)
-	CC := gcc
-endif
 LD := $(CC)
 CC_LONGVER := $(shell if $(CC) -v 2>/dev/null; then \
 						$(CC) -v 2>&1 ;\
