# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyglet
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library for Python

LICENSE=	BSD

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GL=		gl glu
USE_OPENAL=	al

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_DEFAULT=DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} != "i386"
IGNORE=		crashes or doesn't work on !i386
.endif

post-install:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
