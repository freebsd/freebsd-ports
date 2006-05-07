# New ports collection makefile for: 	greed
# Date created:		13 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	greed
PORTVERSION=	0.81p
CATEGORIES=	ftp www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/$(PORTNAME)/
DISTNAME=	greed.81p

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for downloading files with resume capabilities

ALL_TARGET=	freebsd
WRKSRC=		${WRKDIR}/greed.81p

MANCOMPRESSED=	yes
MAN1=		greed.1
PLIST_FILES=	bin/greed

post-patch:
	${REINPLACE_CMD} -e "s,-funroll-all-loops -ffast-math,${CFLAGS}," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/greed.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
