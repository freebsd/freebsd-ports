# $FreeBSD$

PORTNAME=	crispy-doom
PORTVERSION=	5.8.0
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced-resolution Doom source port based on Chocolate Doom

LICENSE=	GPLv2

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libpng16.so:graphics/png

USES=		autoreconf pkgconfig sdl

USE_SDL=	mixer2 net2 sdl2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	fabiangreffrath
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/crispy-*

.include <bsd.port.mk>
