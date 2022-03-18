PORTNAME=	opentyrian
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.20220318
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style vertical scrolling shooter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig sdl
USE_GITHUB=	yes
USE_SDL=	sdl2 net2

MAKE_ENV=	VCS_IDREV="${DISTVERSION}" \
		gamesdir="${PREFIX}/share"

DATADIR=	${PREFIX}/share/tyrian
PORTSCOUT=	skipv:11402-phase-0.8
SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/linux/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/linux/icons/tyrian-32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TOUCH} ${STAGEDIR}${DATADIR}/.keepme

.include <bsd.port.mk>
