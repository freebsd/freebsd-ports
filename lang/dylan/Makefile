# New ports collection makefile for:    Dylan
# Version required:     2.0
# Date created:         23 Jan 1998
# Whom:                 housel@acm.org
#
# $Id: Makefile,v 1.2 1998/07/14 16:15:13 jdp Exp $
#

DISTNAME=	gd20-source
PKGNAME=	dylan-2.0
CATEGORIES=	lang
MASTER_SITES=	http://legend.gwydion.cs.cmu.edu/gwydion/dylan/release/ http://www.freebsd.org/~hsu/ports/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} d2c_2_0-FreeBSD.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER= 	housel@acm.org

WRKSRC=		$(WRKDIR)/src

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=$(PREFIX) --srcdir=$(WRKSRC)
CONFIGURE_ENV=	D2C="$(WRKDIR)/d2c -p$(WRKSRC)/d2c/compiler/platforms.descr"

USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	default

post-extract:
	$(GUNZIP_CMD) -c $(DISTDIR)/d2c_2_0-FreeBSD.gz > $(WRKDIR)/d2c
	chmod ugo+x $(WRKDIR)/d2c

.include <bsd.port.mk>
