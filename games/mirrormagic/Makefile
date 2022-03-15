PORTNAME=	mirrormagic
PORTVERSION=	3.0.0
CATEGORIES=	games
MASTER_SITES=	https://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade style game with stereo sound for X Window System

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5 sdl
USE_SDL=	sdl2 mixer2 image2 net2
USE_PERL5=	build
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	TARGET=sdl2 \
		RO_GAME_DIR="${DATADIR}" \
		RW_GAME_DIR="/var/games/${PORTNAME}"

PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Mirror Magic" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -r ${WRKSRC}/lib ${WRKSRC}/mirrormagic # linux binaries

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rocksndiamonds \
		${STAGEDIR}${PREFIX}/bin/mirrormagic
	cd ${WRKSRC} && ${COPYTREE_SHARE} "conf docs graphics levels music sounds" \
		${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}/var/games/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
