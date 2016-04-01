# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyglet
PORTVERSION=	1.1.4
PORTREVISION=	5
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library for Python

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/lib/libavbin.so:multimedia/avbin

ONLY_FOR_ARCHS=	i386

USES=		openal:al python
USE_PYTHON=	distutils
USE_GL=		gl glu

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG NOTICE README ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
