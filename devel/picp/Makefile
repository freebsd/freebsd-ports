# New ports collection makefile for:    picp
# Date created:         25 October 2002
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	picp
PORTVERSION=	0.5d
CATEGORIES=	devel
MASTER_SITES=	http://www.cosmodog.com/pic/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Driver for the Microchip Picstart Plus development programmer

PLIST_FILES=	bin/picp
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picp ${PREFIX}/bin

.include <bsd.port.mk>
