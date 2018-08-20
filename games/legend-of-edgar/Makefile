# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edgar
DISTVERSION=	1.29
CATEGORIES=	games
MASTER_SITES=	https://github.com/riksweeney/edgar/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	legend-of-
DISTFILES=	edgar-${DISTVERSION}-1${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	2D platform game with a persistent world

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/license

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake
USE_SDL=	image mixer sdl ttf
MAKEFILE=	makefile
MAKE_ARGS=	BIN_DIR=${PREFIX}/bin/ \
		DATA_DIR=${DATADIR}/ \
		MAN_DIR=${PREFIX}/man/man6/ \
		PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

PORTDOCS=	*

NLS_MAKE_ARGS_OFF=	LOCALE_MO=""
NLS_USES=		gettext-tools

post-patch:
	@${REINPLACE_CMD} -e 's|Categories=Game|Categories=Game;ArcadeGame;|' \
		${WRKSRC}/icons/${PORTNAME}.desktop

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
