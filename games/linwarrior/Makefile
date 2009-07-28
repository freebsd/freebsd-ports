# New ports collection makefile for:	linwarrior
# Date created:		31 Dec 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linwarrior
PORTVERSION=	20090529
CATEGORIES=	games
MASTER_SITES=	http://www.hackcraft.de/games/linwarrior_3d/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Navigate a mech through a 3D world and fire at enemies

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut

USE_GMAKE=	yes
USE_GL=		gl glu
USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.2+

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800007
EXTRA_PATCHES=	${FILESDIR}/extra-patch-source-cMech.cpp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/source/cMech.cpp \
		${WRKSRC}/source/cWeapon.cpp ${WRKSRC}/source/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}/sound
	${INSTALL_DATA} ${WRKSRC}/data/sound/*.wav ${DATADIR}/sound

.include <bsd.port.post.mk>
