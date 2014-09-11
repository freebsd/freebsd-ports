# $FreeBSD$

PORTNAME=	sdl2
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/marcusva/py-sdl2/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySDL2-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python bindings to the SDL2 libraries

LICENSE=	ZLIB

USES=		python
USE_SDL=	sdl2 gfx2 image2 ttf2 mixer2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/html
	@${TAR} -C ${WRKSRC}/doc/html -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR}/html -xf -
.endif

.include <bsd.port.mk>
