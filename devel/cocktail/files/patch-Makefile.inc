--- ../../work/cocktail-9309//./Makefile.inc	Sun Apr  4 18:01:21 2004
+++ ./Makefile.inc	Wed Mar 31 23:30:53 2004
@@ -0,0 +1,60 @@
+# Choose a suitable C compiler
+# usually cc or gcc will do
+# on HP700 use: CC = c89 -D_HPUX_SOURCE
+CC     ?= gcc
+
+OPT     = -g -O -w    	# (optimizer) flags for the C compiler
+CFLAGS  += $(OPT) -D$(UNIX) -D$(TARGET) 
+                # C libraries
+
+# Choose a suitable Modula compiler
+# MC or M2C
+MC      = MC
+
+# BSD needs this
+MAKE    = make
+
+BIN 	= $(ROOTDIR)/bin
+LIB 	= $(ROOTDIR)/reuse/m2c		# There are 2 different libraries
+LIBC	= $(ROOTDIR)/reuse/c		# to link against, depending on the 
+INCDIR 	= $(ROOTDIR)/reuse/m2c		# tool. And they cannot be exchanged
+INCDIRC	= $(ROOTDIR)/reuse/c
+REUSE	= libreuse.a
+REUSELIB   = $(INCDIR)/libreuse.a
+REUSELIBC  = $(INCDIRC)/libreuse.a
+COMMONINC  = $(ROOTDIR)/common/m2c
+COMMONLIB  = $(COMMONINC)/libcommon.a
+FRONTINC   = $(ROOTDIR)/front/m2c
+FRONTLIB   = $(FRONTINC)/libfront.a
+
+DEST	= $(PREFIX)
+DESTBIN = $(DEST)/bin	 		# to install shell scripts and binaries
+DESTLIB = $(DEST)/libexec/cocktail 	# to install binaries and data files
+DESTINCDIR  = $(DEST)/include/cocktail 	# Where to put include files for reuse
+DESTMANDIR  = $(DEST)/man/man1	 	# Directory for man pages
+DESTMANDIR2  = $(DEST)/man/man2	 	# Directory for man pages
+
+# During package build
+REX	= $(ROOTDIR)/rex/m2c/rex -l$(ROOTDIR)/rex/lib
+LALR	= $(ROOTDIR)/lalr/m2c/lalr
+MTC	= $(ROOTDIR)/mtc/m2c/mtc
+SED	= sed
+
+# The following targets are legal:
+# PCS10
+# PCS20
+# SUN (this is valid for all others)
+TARGET  = FREEBSB
+UNIX	= UNIX
+
+# Choose the source language:
+LANGUAGE = c
+# LANGUAGE = modula
+
+.SUFFIXES: .md .mi .h .c .o
+
+.mi.c:
+	mtc2 $(M2FLAGS) $*.mi;
+
+.md.h:
+	mtc2 $(M2FLAGS) $*.md;
+
