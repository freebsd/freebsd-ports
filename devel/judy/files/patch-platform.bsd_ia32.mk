--- make_includes/platform.bsd_ia32.mk.orig	Thu Aug 19 14:55:28 2004
+++ make_includes/platform.bsd_ia32.mk	Thu Aug 19 14:59:35 2004
@@ -3,12 +3,11 @@
 # Makefile fragment for Judy* for platform "freebsd_ia32".
 # See platform.hpux_pa.mk for more comments.
 
-SHELL	= /bin/sh
 
 # For portability use the generic names for cc, ld, and ar, which are typically
 # symlinks to more specific names, such as /usr/bin/cc -> /opt/ansic/bin/cc.
 
-CCPATH	= cc
+CCPATH	= %%CC%%
 LDPATH	= ld
 ARPATH	= ar
 AR	= $(ARPATH)
@@ -106,7 +105,7 @@
 # flavors, so spell them out here by flavor, meaning this file cannot be
 # flavor-ignorant:
 
-CC_OPTS_product = -Wall -O2
+CC_OPTS_product = $(CFLAGS)
 CC_OPTS_cov	= -Wall -O -DJU_FLAVOR_COV
 CC_OPTS_debug	= -Wall -g -DJU_FLAVOR_DEBUG
 
