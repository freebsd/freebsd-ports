--- ./common.mk.orig	Tue Mar 15 15:35:46 2005
+++ ./common.mk	Thu Jan 25 11:36:02 2007
@@ -1,18 +1,18 @@
 SHELL = /bin/sh
 
-prefix = /usr
+prefix = $(PREFIX)
 bindir = $(prefix)/bin
 sbindir = $(prefix)/sbin
 libdir = $(prefix)/lib
 
-INSTALL = /usr/bin/install
-INSTALLDATA = /usr/bin/install -m 644
-CC = gcc
-LD = ld
-RM = rm -f
-RMDIR = rmdir -p --ignore-fail-on-non-empty
+INSTALL ?= /usr/bin/install
+INSTALLDATA = $(BSD_INSTALL_DATA)
+CC ?= gcc
+LD ?= ld
+RM ?= rm -f
+RMDIR = -rmdir -p
 
-CFLAGS = -DDEBUG -g -Wall
+CFLAGS += -DDEBUG -g -Wall
 
 PLATFORM := $(shell uname)
 ifeq "$(PLATFORM)" "Linux"
@@ -26,7 +26,7 @@
 
 ifeq "$(PLATFORM)" "FreeBSD"
 CFLAGS_MAIN		= $(CFLAGS) -rdynamic \
-		-DMASTERSERVER_LIB_DIR=\"/usr/lib/lasange/masterserver\"
+		-DMASTERSERVER_LIB_DIR=\"$(libdir)/masterserver\"
 CFLAGS_PLUGIN	= $(CFLAGS) -fPIC
 CFLAGS_TESTS	= $(CFLAGS) -lm
 LDFLAGS			= -pthread
