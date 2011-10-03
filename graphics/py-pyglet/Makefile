# New ports collection makefile for:	pyglet
# Date created:		12 Aug 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyglet
PORTVERSION=	1.1.4
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library for Python

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		gl glu
USE_OPENAL=	al

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		crashes or doesn't work on !i386
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
