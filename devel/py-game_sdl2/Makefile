# $FreeBSD$

PORTNAME=	game_sdl2
PORTVERSION=	6.99.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://www.renpy.org/dl/${PORTVERSION}/ \
		GENTOO/distfiles
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-for-renpy-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Reimplementation of portions of the pygame API using SDL2

LICENSE=	LGPL21 ZLIB
LICENSE_COMB=	multi

BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png

USES=		python:2.7 tar:bz2
USE_SDL=	gfx2 image2 mixer2 ttf2
USE_PYTHON=	autoplist distutils
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
