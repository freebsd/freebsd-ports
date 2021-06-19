PORTNAME=	linwarrior
PORTVERSION=	20100320
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.hackcraft.de/games/linwarrior_3d/downloads/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Navigate a mech through a 3D world and fire at enemies

USES=		compiler:c++11-lang gl gmake openal:al,alut sdl
USE_GL=		gl glu
USE_SDL=	sdl
USE_CXXSTD=	gnu++98

LDFLAGS_i386=	-Wl,-znotext

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="LinWarrior 3D" \
		"Mech Simulation Game" \
		"" \
		"linwarrior" \
		"Game;ActionGame;Simulation;" \
		false

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} a+rx {} \;
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} a+r {} \;

post-patch:
	@${REINPLACE_CMD} -e '/hash_set/ d' ${WRKSRC}/source/cAlert.h
	@${FIND} ${WRKSRC}/source -name '*.cpp' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|data/|${DATADIR}/|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dist/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
