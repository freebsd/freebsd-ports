PORTNAME=	crispy-doom
PORTVERSION=	7.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced-resolution Doom source port based on Chocolate Doom
WWW=		https://github.com/fabiangreffrath/crispy-doom

LICENSE=	GPLv2

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libpng.so:graphics/png \
		libfluidsynth.so:audio/fluidsynth

USES=		autoreconf desktop-file-utils pkgconfig python:build sdl shebangfix

CONFLICTS_INSTALL=	chocolate-doom

USE_CSTD=	c99
USE_SDL=	mixer2 net2 sdl2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	man/docgen man/simplecpp

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	fabiangreffrath

post-patch:
	${REINPLACE_CMD} "s|python3|${PYTHON_VERSION}|" ${WRKSRC}/configure.ac

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/crispy-*-setup

.include <bsd.port.mk>
