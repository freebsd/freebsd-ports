# New ports collection makefile for: amulet
# Version required:   3.0
# Date created:       26 July 1997
# Whom:               Filip Bovyn (bovynf@awe.be)
#
# $Id: Makefile,v 1.2 1998/08/05 09:30:47 asami Exp $

DISTNAME=	amulet
PKGNAME=	amulet-3.0
CATEGORIES=	devel x11
MASTER_SITES=	http://www.cs.cmu.edu/afs/cs/project/amulet/amulet3/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	bovynf@awe.be

USE_X_PREFIX=	yes
WRKSRC=		$(WRKDIR)/amulet
MAKE_ENV=	AMULET_DIR=$(WRKSRC) AMULET_VARS_FILE=Makefile.vars.gcc.FreeBSD

pre-build:
	${CP} $(FILESDIR)/Makefile.vars.gcc.FreeBSD $(WRKSRC)/bin

do-build:
	@(cd $(WRKSRC)/bin; $(MAKE_ENV) $(MAKE) libs)
	@(cd $(WRKSRC)/bin; $(MAKE_ENV) $(MAKE) all)

SAMPLES=	av\
		testdpy\
		testgem\
		testtrans\
		testsubwins\
		testloop\
		testclip\
		testpoints\
		testwinsizes\
		testinput\
		testcopy\
		testobject\
		testopal\
		testJIO\
		testpolyweb\
		testlines\
		testgobs\
		testmap\
		hsv\
		testloadsave\
		testinter\
		testaniminter\
		testwidgets\
		testselectionwidget\
		testdragdrop\
		testmaps\
		testgest\
		testfade\
		testflip\
		testanimators\
		testrichtext\
		testpixmap\
		checkers\
		circuit\
		color\
		hello\
		goodbye_inter\
		goodbye_button\
		space\
		space2\
		timing\
		tutorial\
		tree\
		example1\
		example2

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/lib/libamulet.so.3.0 $(PREFIX)/lib
	$(INSTALL_PROGRAM) $(WRKSRC)/lib/libamulet-release.so.3.0 $(PREFIX)/lib
	$(INSTALL_DATA)    $(WRKSRC)/lib/libamulet-release.a $(PREFIX)/lib
	$(LDCONFIG) -m $(PREFIX)/lib
	$(INSTALL_PROGRAM) $(WRKSRC)/bin/gilt $(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/bin/agate $(PREFIX)/bin
	${MKDIR} $(PREFIX)/include/amulet
	$(INSTALL_DATA) $(WRKSRC)/include/*.h $(PREFIX)/include
	$(INSTALL_DATA) $(WRKSRC)/include/amulet/* $(PREFIX)/include/amulet
	${MKDIR} $(PREFIX)/share/amulet/lib
	$(INSTALL_DATA) $(WRKSRC)/lib/select.cl $(PREFIX)/share/amulet/lib/select.cl
	${MKDIR} $(PREFIX)/share/amulet/lib/images
	$(INSTALL_DATA) $(WRKSRC)/lib/images/* $(PREFIX)/share/amulet/lib/images
	${MKDIR} $(PREFIX)/share/amulet/samples
	$(INSTALL_DATA) $(FILESDIR)/sample.Makefile $(PREFIX)/share/amulet/samples
	(for a in $(SAMPLES); \
	 do \
	   $(INSTALL_PROGRAM) $(WRKSRC)/bin/$$a $(PREFIX)/share/amulet/samples; \
	 done)

.include <bsd.port.mk>
