###############################################################################
# Configuration section:  look at sections (1) to (4) below, making
#      changes that seem necessary.  For many UNIX systems, no changes
#      should be necessary, but check especially the compiler options in
#      section (4).
#
###############################################################################
#
# (1)  You need to define the symbols NABHOME and ARCH, either on the
#    make command line (e.g. "make ARCH=sun4 NABHOME=/thr/eigen/nab5")
#    or as environment variables.
#
#    NABHOME should be an absolute path to this directory.
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
BINDIR=$(NABHOME)/bin/$(ARCH)
LIBDIR=$(NABHOME)/lib/$(ARCH)
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
#
#  following for linking in fortran subroutines on Sun4, Solaris 2.x
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
#          For GNU:  cc-->gcc; lex-->flex; yacc-->bison -y -t;
#          Note: If you lexer is "really" flex, you need to set
#          LEX=flex below.  For example, on many linux distributions,
#          /usr/bin/lex is really just a pointer to /usr/bin/flex,
#          so LEX=flex is necessary.  In general, gcc seems to need
#          flex.
#
#          For 64-bit IRIX, add "-n32" unless 64-bit objects are 
#          needed; it is also useful to add "-Wl,-dont_warn_unused"
#          to keep the loader from complaining about libraries that
#          are not used.
#
#          For RedHat Linux 5.1 (and other linuxes?) add -DHAVE_STRERROR
#
#	   For FreeBSD 4.2-STABLE, there seems to be a dependency
#	   on bison.  Berkeley yacc was very problematic.
CC=		cc
LEX=    	flex
YACC=   	bison -y -t
AR=		ar
#
#  Set the C-preprocessor.  Code for a small preprocessor is in
#    uccp-0.7;  it gets installed as $(NABHOME)/bin/$(ARCH)/ucpp;
#    this should generally *not* be changed.
#
#  Again, for FreeBSD 4.2-STABLE, I had problems using the system
#    C-preprocessor.
#
CPP=    ucpp -l
#
#  Use these CFLAGS if AVS = 0
#
CFLAGS= -O -pipe
OCFLAGS= -O -pipe
NABFLAGS=
#
#  Use these CFLAGS if AVS = 1
#
#CFLAGS= 	-g -DAVS=$(AVS) -DAVSDIR='"$(AVSDIR)"' -I$(AVSINCDIR)
#OCFLAGS= 	-O -DAVS=$(AVS) -DAVSDIR='"$(AVSDIR)"' -I$(AVSINCDIR)
#
#
#  For Win95/98, set SFX to ".exe"; for Unix,NT leave it empty:
#
#SFX=.exe
SFX=
#
