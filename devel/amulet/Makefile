# New ports collection makefile for: amulet
# Date created:       26 July 1997
# Whom:               Filip Bovyn (bovynf@awe.be)
#
# $FreeBSD$

PORTNAME=	amulet
PORTVERSION=	3.0
CATEGORIES=	devel x11
MASTER_SITES=	http://www-2.cs.cmu.edu/afs/cs/project/amulet/amulet3/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	bovynf@awe.be

USE_GCC=	2.95
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		$(WRKDIR)/amulet
MAKE_ENV=	AMULET_DIR=$(WRKSRC) AMULET_VARS_FILE=Makefile.vars.gcc.FreeBSD

.include <bsd.port.pre.mk>

.if $(PORTOBJFORMAT) == "elf"
SO_VERSION=	3
.else
SO_VERSION=	3.0
.endif

pre-build:
	${CP} $(FILESDIR)/Makefile.vars.gcc.FreeBSD $(WRKSRC)/bin
	${RM} -f ${WRKSRC}/include/amulet/*.orig

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
	$(INSTALL_PROGRAM) $(WRKSRC)/lib/libamulet.so.$(SO_VERSION) $(PREFIX)/lib
	$(LN) -sf libamulet.so.$(SO_VERSION) $(PREFIX)/lib/libamulet.so
	$(INSTALL_PROGRAM) $(WRKSRC)/lib/libamulet-release.so.$(SO_VERSION) $(PREFIX)/lib
	$(LN) -sf libamulet-release.so.$(SO_VERSION) $(PREFIX)/lib/libamulet-release.so
	$(INSTALL_DATA)    $(WRKSRC)/lib/libamulet-release.a $(PREFIX)/lib
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

.include <bsd.port.post.mk>
