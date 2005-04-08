# New ports collection makefile for:	alephone-data
# Date created:		08 March 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone-data
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://files3.bungie.org/trilogy/
DISTNAME=	infinity

MAINTAINER=	malyn@strangeGizmo.com
COMMENT=	Data files for the alephone port

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files.

WRKSRC=		${WRKDIR}/Marathon\ Infinity
DATADIR=	${PREFIX}/share/AlephOne
DATA=		Images Map Map.resources Music Shapes Sounds
PLIST_FILES=	${DATA:S+^+share/AlephOne/+}

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATA} ${DATADIR}

.include <bsd.port.mk>
