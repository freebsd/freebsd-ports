# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	sorl-thumbnail
PORTVERSION=	12.4.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Sorl-thumbnail provides an easy way to generate image thumbnails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.8:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	PILLOW
OPTIONS_SINGLE=		IMAGELIB
OPTIONS_GROUP=		CACHING

OPTIONS_SINGLE_IMAGELIB=	GRAPHICSMAGICK IMAGEMAGICK PILLOW WAND
OPTIONS_GROUP_CACHING=		REDIS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

GRAPHICSMAGICK_RUN_DEPENDS=	${LOCALBASE}/bin/gm:graphics/GraphicsMagick
IMAGEMAGICK_RUN_DEPENDS=	${LOCALBASE}/bin/convert:graphics/ImageMagick6
REDIS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}
WAND_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}Wand>0:graphics/py-wand@${PY_FLAVOR}

GRAPHICSMAGICK_DESC=	Use GraphicsMagick for image processing (faster)
IMAGEMAGICK_DESC=	Use ImageMagick for image processing
PILLOW_DESC=		Use internal image processing
REDIS_DESC=		Use REDIS as Key Value Store
WAND_DESC=		Use Wand with ImageMagick

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPILLOW}
.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow6>0:graphics/py-pillow6@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
.endif
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.post.mk>
