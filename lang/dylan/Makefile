# New ports collection makefile for:    Dylan
# Version required:     2.0
# Date created:         23 Jan 1998
# Whom:                 housel@acm.org
#
# $Id: Makefile,v 1.4 1998/10/14 00:08:48 jseger Exp $
#

DISTNAME=	gd-2.2.0
PKGNAME=	dylan-2.2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://berlin.ccc.de/pub/gd/src/ \
		ftp://berlin.ccc.de/pub/gd/FreeBSD/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} d2c-2.2.0-FreeBSD.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER= 	housel@acm.org

WRKSRC=		$(WRKDIR)/gd/src

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=$(PREFIX) --srcdir=$(WRKSRC)
CONFIGURE_ENV=	D2C="$(WRKDIR)/d2c"

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	default

MAN1=		d2c.1 make-dylan-app.1 melange.1 mindy.1 mindycomp.1
MAN5=		platforms.descr.5
MAN7=		dylan.7 gwydion.7

post-extract:
	$(GUNZIP_CMD) -c $(DISTDIR)/d2c-2.2.0-FreeBSD.gz > $(WRKDIR)/d2c
	chmod ugo+x $(WRKDIR)/d2c

.include <bsd.port.mk>
