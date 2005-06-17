# New ports collection makefile for:   marathon2-data
# Date created:                19 March 2005
# Whom:                        Evan T. Dower <evantd@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	marathon2-data
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://files3.bungie.org/trilogy/
DISTNAME=	marathon2

MAINTAINER=	evantd@yahoo.com
COMMENT=	Data files for the alephone port from Marathon 2

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files.
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/AlephOne
	${INSTALL_DATA} ${WRKDIR}/Images ${PREFIX}/share/AlephOne/Durandal.Images
	${INSTALL_DATA} ${WRKDIR}/Map ${PREFIX}/share/AlephOne/Durandal.Map
	${INSTALL_DATA} ${WRKDIR}/Map.resources ${PREFIX}/share/AlephOne/Durandal.Map.resources
	${INSTALL_DATA} ${WRKDIR}/Music ${PREFIX}/share/AlephOne/Durandal.Music
	${INSTALL_DATA} ${WRKDIR}/Shapes ${PREFIX}/share/AlephOne/Durandal.Shapes
	${INSTALL_DATA} ${WRKDIR}/Sounds ${PREFIX}/share/AlephOne/Durandal.Sounds

.include <bsd.port.mk>
