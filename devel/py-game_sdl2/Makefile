PORTNAME=	game_sdl2
PORTVERSION=	7.4.11
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	http://www.renpy.org/dl/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-2.1.0-for-renpy-${DISTVERSION}

MAINTAINER=	social@brandongrows.me
COMMENT=	Reimplementation of portions of the pygame API using SDL2
WWW=		https://github.com/renpy/pygame_sdl2

LICENSE=	LGPL21+ ZLIB
LICENSE_COMB=	multi

LIB_DEPENDS=	libpng.so:graphics/png

USES=		jpeg localbase python:2.7+ sdl
USE_PYTHON=	autoplist distutils cython
USE_SDL=	image2 mixer2 ttf2

BINARY_ALIAS=	cython=cython-${PYTHON_VER}
EXCLUDE=	gen gen3 PKG-INFO '*.egg-info'
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
# Upstream tends to reroll distfiles before moving under /release/
PORTSCOUT=	site:http://www.renpy.org/dl/release/

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
