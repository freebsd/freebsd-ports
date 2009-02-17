# New ports collection makefile for:	linwarrior
# Date created:		31 Dec 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linwarrior
PORTVERSION=	20090208
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.hackcraft.de/games/linwarrior_3d/downloads/ \
		http://mirror.amdmi3.ru/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Navigate a mech through a 3D world and fire at enemies

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut

USE_GMAKE=	yes
USE_GL=		gl glu
USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/source/cMech.cpp \
		${WRKSRC}/source/cWeapon.cpp ${WRKSRC}/source/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}/sound
	${INSTALL_DATA} ${WRKSRC}/data/sound/*.wav ${DATADIR}/sound

.include <bsd.port.mk>
