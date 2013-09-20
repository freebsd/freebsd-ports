# $FreeBSD$

PORTNAME=	sdl2
PORTVERSION=	0.6.0
CATEGORIES=	devel python
MASTER_SITES=	http://cdn.bitbucket.org/marcusva/py-sdl2/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PySDL2-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Python bindings to the SDL2 libraries

USE_SDL=		sdl2 image2 ttf2 mixer2
USE_PYTHON=		2.7+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PySDL2

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/html
	@${TAR} -C ${WRKSRC}/doc/html -cf - . | \
		${TAR} -C ${DOCSDIR}/html -xf -
.endif

.include <bsd.port.mk>
