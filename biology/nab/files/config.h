###############################################################################
# Configuration section:  look at sections (1) to (4) below, making
#      changes that seem necessary.  For most UNIX systems, no changes
#      should be necessary.
#
###############################################################################
#
# (1)  You need to define the symbols NABHOME and ARCH, either on the
#    make command line (e.g. "make ARCH=sun4 NABHOME=/thr/eigen/nab5")
#    or as environment variables.
#
#    NABHOME should be an absolute path to the directory above this one.
#    ARCH is used to distinguish compilations for various architectures.
#
#    Files created by "make install" end up in:
#        $NABHOME/bin/$ARCH
#        $NABHOME/lib/$ARCH
#        $NABHOME/include
#
#       You can choose ARCH as you wish, but it would generally 
#       be related to the output of the "uname" command.
#
#BINDIR=$(NABHOME)/bin/$(ARCH)
#LIBDIR=$(NABHOME)/lib/$(ARCH)
#NABHOME=/usr/local/share/nab
#ARCH=
BINDIR=$(NABHOME)/bin
LIBDIR=$(NABHOME)/lib
INCDIR=$(NABHOME)/include
#
###############################################################################
#
#
#  (2) If you want to search additional libraries by default, add them
#      to the FLIBS variable here.  (External libraries can also be linked into
#      NAB programs simply by including them on the command line; libraries
#      included in FLIBS are always searched.)
#
#FLIBS=$(LIBDIR)/cifparse.a $(LIBDIR)/libsym.a
#FLIBS=../cifparse/cifparse.a
#
#  following for Sun4, Solaris 2.x
#
#FLIBS=$(LIBDIR)/cifparse.a $(LIBDIR)/libsym.a -lF77 -lM77 -lsunmath
#
#  following for HP-UX
#
#FLIBS=$(LIBDIR)/cifparse.a $(LIBDIR)/libsym.a lapack.a blas.a -lf -lvec
#
###############################################################################
#
#  (3)  Set AVS to 1 if you want AVS support; if so, set AVSDIR to point to
#       your AVS distribution.  The directories $AVSDIR/include and $AVSDIR/lib
#       must exist, and CFLAGS (below) must also be modified for AVS support.
#
AVS=		0
#
#AVSDIR=	/tsri/avs/$(ARCH)/avs
#AVSINCDIR=	$(AVSDIR)/include
#
#
###############################################################################
#
#  (4)  Modify any of the following if you need to change, e.g. to use gcc
#        rather than cc, etc.
#
#
SHELL=		/bin/sh
#
#  Set the C compiler, etc. 
#
#               (For GNU:  cc-->gcc; lex-->flex; yacc-->bison -y -t;
#                Note: If you lexer is "really" flex, you need to set
#                LEX=flex below.  For example, on many linux distributions,
#                /usr/bin/lex is really just a pointer to /usr/bin/flex,
#                so LEX=flex is necessary.  In general, gcc seems to need
#                flex.)
#
CC=		cc
LEX=    	flex
YACC=   	yacc
AR=		ar
#
#  Set the C-preprocessor.  Code for the preprocessor from gcc is in
#    ../cccp;  it gets installed as $(NABHOME)/bin/$(ARCH)/cpp;
#    this should generally *not* be changed.
#
#CPP=    $(NABHOME)/bin/$(ARCH)/cpp -lang-c++
#CPP=    ../cccp/cpp -lang-c++
CPP=    cc -E -x c++
#
#  Use these CFLAGS if AVS = 0
#  Notes: for 64-bit IRIX, add "-n32" to both CFLAGS and OCFLAGS
#         for RedHat Linux 5.1 (and other linuxes?) add -DHAVE_STRERROR
#
OCFLAGS= -O
CFLAGS= -DHAVE_STRERROR ${OCFLAGS}
NABFLAGS=
#
#  Use these CFLAGS if AVS = 1
#
#CFLAGS= 	-g -DAVS=$(AVS) -DAVSDIR='"$(AVSDIR)"' -I$(AVSINCDIR)
#OCFLAGS= 	-O -DAVS=$(AVS) -DAVSDIR='"$(AVSDIR)"' -I$(AVSINCDIR)
#
#
#  For Win95, set SFX to ".exe"; for Unix,NT leave it empty:
#
#SFX=.exe
SFX=
#
