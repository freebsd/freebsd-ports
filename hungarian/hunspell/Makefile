# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.6.1
CATEGORIES=	hungarian textproc
MASTER_SITES=	SF/magyarispell/Magyar%20Ispell/${PORTVERSION}
DISTNAME=	hu_HU-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Hunspell Hungarian dictionary

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/hu_HU-${PORTVERSION}

PLIST_FILES=	%%DATADIR%%/hu_HU.aff \
		%%DATADIR%%/hu_HU.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hu_HU.aff ${WRKSRC}/hu_HU.dic ${DATADIR}/

.include <bsd.port.mk>
