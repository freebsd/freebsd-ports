# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edgar
DISTVERSION=	1.32
CATEGORIES=	games
MASTER_SITES=	https://github.com/riksweeney/edgar/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	legend-of-
DISTFILES=	edgar-${DISTVERSION}-1${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	2D platform game with a persistent world

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/license

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake sdl
USE_SDL=	image2 mixer2 sdl2 ttf2
MAKEFILE=	makefile
MAKE_ARGS=	BIN_DIR=${PREFIX}/bin/ \
		DATA_DIR=${DATADIR}/ \
		MAN_DIR=${PREFIX}/man/man6/ \
		PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-tools
NLS_MAKE_ARGS_OFF=	LOCALE_MO=""

post-patch:
	@${REINPLACE_CMD} -e 's|Categories=Game|Categories=Game;ArcadeGame;|' \
		${WRKSRC}/icons/${PORTNAME}.desktop

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
