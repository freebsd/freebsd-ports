PORTNAME=	crispy-doom
PORTVERSION=	5.10.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced-resolution Doom source port based on Chocolate Doom

LICENSE=	GPLv2

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libpng.so:graphics/png

CONFLICTS_INSTALL=	chocolate-doom

USES=		autoreconf pkgconfig python:build sdl shebangfix
USE_CSTD=	c99
USE_SDL=	mixer2 net2 sdl2
GNU_CONFIGURE=	yes
SHEBANG_FILES=	man/docgen man/simplecpp

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	fabiangreffrath

post-patch:
	${REINPLACE_CMD} "s|python3|${PYTHON_VERSION}|" ${WRKSRC}/configure.ac

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/crispy-*

.include <bsd.port.mk>
