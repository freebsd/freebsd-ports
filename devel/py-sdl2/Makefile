# $FreeBSD$

PORTNAME=	sdl2
PORTVERSION=	0.9.5
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/marcusva/py-sdl2/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySDL2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings to the SDL2 libraries

LICENSE=	PD CC0-1.0 ZLIB
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/doc/copying.rst

USES=		python
USE_SDL=	sdl2 gfx2 image2 ttf2 mixer2
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo"

.include <bsd.port.mk>
