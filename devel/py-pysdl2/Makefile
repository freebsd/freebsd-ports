PORTNAME=	pysdl2
PORTVERSION=	0.9.16
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySDL2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings to the SDL2 libraries
WWW=		https://github.com/py-sdl/py-sdl2

LICENSE=	PD CC0-1.0 ZLIB
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/doc/copying.rst

USES=		dos2unix python sdl
USE_PYTHON=	autoplist concurrent distutils
USE_SDL=	gfx2 image2 mixer2 sdl2 ttf2

NO_ARCH=	yes

.include <bsd.port.mk>
