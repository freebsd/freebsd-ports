# New ports collection makefile for:	doom-freedoom
# Date created:				23 November 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	freedoom
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-iwad-${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Complete Doom-based game IWAD that is Free Software

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/doom2.wad
PLIST_DIRS=	%%DATADIR%%

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/doom2.wad ${DATADIR}

.include "${.CURDIR}/../../games/doom-data/Makefile.include"

.include <bsd.port.mk>
