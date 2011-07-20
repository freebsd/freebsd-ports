# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.6.1
CATEGORIES=	hungarian textproc
MASTER_SITES=	SF/magyarispell/Magyar%20Ispell/${DICTVERSION}
DISTNAME=	hu_HU-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Hunspell hungarian dictionnary

NO_BUILD=	yes
WRKSRC=	${WRKDIR}/hu_HU-${PORTVERSION}

PLIST_FILES=	share/hunspell/hu_HU.dic \
		share/hunspell/hu_HU.aff

PLIST_DIRS=	share/hunspell

do-install:
	${MKDIR} ${PREFIX}/share/hunspell/
	${INSTALL_DATA} ${WRKSRC}/hu_HU.dic \
		${WRKSRC}/hu_HU.aff \
		${PREFIX}/share/hunspell/

.include <bsd.port.mk>
