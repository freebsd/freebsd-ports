# New ports collection makefile for:   stars-1.0
# Version required:	1.0
# Date created:		10 Jul 1996
# Whom:			searle
#
# $Id$
#

DISTNAME=	stars-1.0-ss-9.03
PKGNAME=	stars-1.0
CATEGORIES+=	x11
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/X11/Demos/stars-1.0/ \
		ftp://askdonald.ask.uni-karlsruhe.de/hpux/X11/Demos/stars-1.0/

MAINTAINER=	searle@longacre.demon.co.uk

USE_X11=	yes
WRKSRC=		$(WRKDIR)/$(PKGNAME)

do-build:
	cc -I$(PREFIX)/include -O2 -c $(WRKSRC)/xwin.c -o $(WRKSRC)/xwin.o
	cc -I$(PREFIX)/include -O2 -c $(WRKSRC)/main.c -o $(WRKSRC)/main.o
	cc $(WRKSRC)/main.o $(WRKSRC)/xwin.o -L$(PREFIX)/lib -lX11 -lm -o $(WRKSRC)/stars

do-install:
	install -c $(WRKSRC)/stars $(PREFIX)/bin/stars

.include <bsd.port.mk>
