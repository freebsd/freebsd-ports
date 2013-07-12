# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linwarrior
PORTVERSION=	20100320
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.hackcraft.de/games/linwarrior_3d/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Navigate a mech through a 3D world and fire at enemies

USE_GMAKE=	yes
USE_OPENAL=	al alut
USE_GL=		gl glu
USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes
USE_GCC=	4.2+

WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES="LinWarrior 3D" \
		"Mech Simulation Game" \
		"" \
		"linwarrior" \
		"Game;ActionGame;Simulation;" \
		false

post-extract:
	@${FIND} ${WRKSRC} -type d -exec chmod a+rx {} \;
	@${FIND} ${WRKSRC} -type f -exec chmod a+r {} \;

post-patch:
	@${REINPLACE_CMD} -e '/hash_set/ d' ${WRKSRC}/source/cAlert.h
	@${FIND} ${WRKSRC}/source -name '*.cpp' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|data/|${DATADIR}/|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} '*' ${DATADIR}/

.include <bsd.port.mk>
