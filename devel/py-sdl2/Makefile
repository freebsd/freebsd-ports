# $FreeBSD$

PORTNAME=	sdl2
PORTVERSION=	0.9.5
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/marcusva/py-sdl2/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySDL2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings to the SDL2 libraries

LICENSE=	ZLIB

USES=		python
USE_SDL=	sdl2 gfx2 image2 ttf2 mixer2
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${TAR} -C ${WRKSRC}/doc/html -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR}/html -xf -

.include <bsd.port.mk>
