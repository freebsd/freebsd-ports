--- c.mk.orig	Mon Dec  9 14:32:33 2002
+++ c.mk	Fri Dec 27 05:10:26 2002
@@ -13,9 +13,11 @@
 # install make+ separately.
 
 # General C compilation variables.
-CC		= gcc
-CFLAGS		= -I. -I..
-LIBS		=
+CC		?= gcc
+CFLAGS		+= -I. -I..
+LIBS		+=
+SETENV		?= /usr/bin/env
+CONF_ENV	= CC="$(CC)" CFLAGS="$(CFLAGS)"
 
 # Link scripts.
 MP_LINK_STATIC	= $(MAKEPLUS_HOME)/link_static.sh
