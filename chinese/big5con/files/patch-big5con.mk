--- big5con.mk.orig	Thu Oct  8 13:09:50 1998
+++ big5con.mk	Tue Nov 26 11:45:51 2002
@@ -29,7 +29,7 @@
 	  -DXCIN_DIR=\"$(XCIN_DIR)\" $(ALT_META) $(EXTRA_OPTS)
 CC	= gcc
 #CFLAGS  = -O2 -m486 $(OPTS)
-CFLAGS  += -O2 $(OPTS)
+CFLAGS  += $(OPTS)
 LD      = gcc $(CFLAGS)
 RM      = rm -f
 INSTALL = install -c
