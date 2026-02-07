--- configs/freebsd.mk.orig	2024-07-14 11:26:54 UTC
+++ configs/freebsd.mk
@@ -5,20 +5,20 @@ ARCH = x86_64
 # variables used during build
 PLATFORM = freebsd
 ARCH = x86_64
-HARECFLAGS =
+HARECFLAGS = -a ${ARCH}
 QBEFLAGS =
 ASFLAGS =
 LDLINKFLAGS = --gc-sections -z noexecstack
-CFLAGS = -g -std=c11 -D_XOPEN_SOURCE=700 -Iinclude \
+CFLAGS += -std=c11 -D_XOPEN_SOURCE=700 -Iinclude \
 	-Wall -Wextra -Werror -pedantic -Wno-unused-parameter
-LDFLAGS =
-LIBS = -lm
+LDFLAGS ?=
+LIBS += -lm
 
 # commands used by the build script
-CC = cc
-AS = as
-LD = ld
-QBE = qbe
+CC ?= cc
+AS ?= as
+LD ?= ld
+QBE ?= qbe
 
 # build locations
 HARECACHE = .cache
@@ -26,4 +26,4 @@ DEFAULT_TARGET = $(ARCH)
 
 # variables that will be embedded in the binary with -D definitions
 DEFAULT_TARGET = $(ARCH)
-VERSION = $$(./scripts/version)
+VERSION ?= $$(./scripts/version)
