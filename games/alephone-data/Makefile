# New ports collection makefile for:	alephone-data
# Date created:		08 March 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	alephone-data
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	marathon
DISTNAME=	AlephOne-minf-demo

MAINTAINER=	malyn@strangeGizmo.com

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files.

do-install:
	@${MKDIR} ${PREFIX}/share/AlephOne
	@${MKDIR} ${PREFIX}/share/AlephOne/MML
	${INSTALL_DATA} ${WRKDIR}/Images ${PREFIX}/share/AlephOne/Images
	${INSTALL_DATA} ${WRKDIR}/MML/Preferences.mml ${PREFIX}/share/AlephOne/MML/Preferences.mml
	${INSTALL_DATA} ${WRKDIR}/Map ${PREFIX}/share/AlephOne/Map
	${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/AlephOne/README
	${INSTALL_DATA} ${WRKDIR}/Shapes ${PREFIX}/share/AlephOne/Shapes
	${INSTALL_DATA} ${WRKDIR}/Sounds ${PREFIX}/share/AlephOne/Sounds

.include <bsd.port.mk>
