PORTNAME=	edgar
DISTVERSION=	1.37
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/riksweeney/edgar/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	legend-of-
DISTFILES=	edgar-${DISTVERSION}-1${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D platform game with a persistent world
WWW=		https://www.parallelrealities.co.uk/games/edgar/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/license

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake sdl
USE_SDL=	image2 mixer2 sdl2 ttf2
MAKEFILE=	makefile
MAKE_ARGS=	BIN_DIR=${PREFIX}/bin/ \
		DATA_DIR=${DATADIR}/ \
		PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-tools
NLS_MAKE_ARGS_OFF=	LOCALE_MO=""

post-patch:
	${REINPLACE_CMD} -e 's|Categories=Game;|Categories=Game;ArcadeGame;|' \
		${WRKSRC}/icons/${PORTNAME}.desktop

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
