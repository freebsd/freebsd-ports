--- /usr/ports/devel/cocktail/work/cocktail-9309//./Makefile.inc	Sat Sep 11 00:58:46 2004
+++ ./Makefile.inc	Fri Sep 10 15:46:35 2004
@@ -0,0 +1,96 @@
+# Choose a suitable C compiler
+# usually cc or gcc will do
+# on HP700 use: CC = c89 -D_HPUX_SOURCE
+CC     ?= gcc
+
+OPT     = -g      	# (optimizer) flags for the C compiler
+WARNINGS= -W -Wall -ansi  -Wcast-align \
+        -Wcast-qual -Wchar-subscripts -Winline \
+	-Wnested-externs -Wpointer-arith \
+	-Wmissing-prototypes \
+        -Wredundant-decls \
+	-Wno-shadow \
+	-Wno-parentheses \
+	-Wno-unused 
+TWARNINGS= 
+
+#WARNINGS= -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align \
+#	-Waggregate-return -Wstrict-prototypes \
+#	-Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline
+# 	-Wbad-function-cast 
+#		Gives all those: cast does not match function type
+#	-Wconversion , not very handy, since it allerts almost all conversions
+#			als the correct ones
+#	-Wwrite-strings , a nuicance
+#	-Wstrict-prototypes \
+
+CFLAGS  += $(OPT) $(WARNINGS) -D$(UNIX) -D$(TARGET) $(XFLAGS)
+#
+# To compile the tests, since they are tool generated and otherwise generate 
+# losts warnings
+TCFLAGS  += $(OPT) $(TWARNINGS) -D$(UNIX) -D$(TARGET) $(XFLAGS)
+
+# Choose a suitable Modula compiler
+# MC or M2C
+MC      = m2c
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
+TMPDIR	= ${ROOTDIR}/tmp
+TMPBIN	= $(TMPDIR)/bin
+TMPLIB	= $(TMPDIR)/libexec/cocktail
+TMPINC	= $(TMPDIR)/include/cocktail
+
+DEST	= $(PREFIX)
+DESTBIN = $(DEST)/bin	 		# to install shell scripts and binaries
+DESTLIB = $(DEST)/libexec/cocktail 	# to install binaries and data files
+DESTINCDIR  = $(DEST)/include/cocktail 	# Where to put include files for reuse
+DESTMANDIR  = $(DEST)/man/man1	 	# Directory for man pages
+DESTMANDIR2  = $(DEST)/man/man2	 	# Directory for man pages
+
+# During package build
+REX	= $(TMPBIN)/rex
+BNF	= $(TMPBIN)bnf
+LALR	= $(TMPBIN)/lalr
+MTC	= $(TMPBIN)/mtc
+LPP	= $(TMPBIN)/lpp
+RPP	= $(TMPBIN)/rpp
+CG	= $(TMPBIN)/cg
+ELL	= $(TMPBIN)/ell
+PUMA	= $(TMPBIN)/puma
+SED	= sed
+
+STDCLEAN = *.bak *.orig *.rej *.core *.o
+
+# The following targets are legal:
+# PCS10
+# PCS20
+# SUN (this is valid for all others)
+TARGET  = FREEBSD
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
