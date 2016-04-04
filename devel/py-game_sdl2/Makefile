# $FreeBSD$

PORTNAME=	game_sdl2
PORTVERSION=	6.99.10
CATEGORIES=	devel python
MASTER_SITES=	http://www.renpy.org/dl/${PORTVERSION}/ \
		GENTOO
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-2.1.0-for-renpy-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Reimplementation of portions of the pygame API using SDL2

LICENSE=	LGPL21+ ZLIB
LICENSE_COMB=	multi

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS=	libpng.so:graphics/png

# Upstream tends to reroll distfiles before moving under /release/
PORTSCOUT=	site:http://www.renpy.org/dl/release/

USES=		jpeg python
USE_SDL=	image2 mixer2 ttf2
USE_PYTHON=	autoplist distutils
EXCLUDE=	gen gen3 PKG-INFO '*.egg-info'
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
