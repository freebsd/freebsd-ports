# New ports collection makefile for:   stars-1.0
# Version required:	1.0
# Date created:		10 Jul 1996
# Whom:			searle
#
# $Id: Makefile,v 1.5 1998/01/28 21:11:20 jseger Exp $
#

DISTNAME=	stars-1.0-ss-10.10
PKGNAME=	stars-1.0
CATEGORIES=	astro
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/X11/Demos/stars-1.0/ \
		ftp://askdonald.ask.uni-karlsruhe.de/hpux/X11/Demos/stars-1.0/

MAINTAINER=	jseger@FreeBSD.org

USE_X11=	yes
WRKSRC=		$(WRKDIR)/$(PKGNAME)

do-build:
	cc -I$(PREFIX)/include -O2 -c $(WRKSRC)/xwin.c -o $(WRKSRC)/xwin.o
	cc -I$(PREFIX)/include -O2 -c $(WRKSRC)/main.c -o $(WRKSRC)/main.o
	cc $(WRKSRC)/main.o $(WRKSRC)/xwin.o -L$(PREFIX)/lib -lX11 -lm -o $(WRKSRC)/stars

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/stars $(PREFIX)/bin/stars

.include <bsd.port.mk>
