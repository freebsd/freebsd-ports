PORTNAME=	opentyrian
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.20221123
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style vertical scrolling shooter
WWW=		https://github.com/opentyrian/opentyrian

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pkgconfig sdl
USE_GITHUB=	yes
USE_SDL=	sdl2 net2

MAKE_ENV=	VCS_IDREV="${ECHO_CMD} ${DISTVERSION}" \
		gamesdir="${PREFIX}/share"

DATADIR=	${PREFIX}/share/tyrian
PORTSCOUT=	skipv:11402-phase-0.8
SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opentyrian
	@${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
