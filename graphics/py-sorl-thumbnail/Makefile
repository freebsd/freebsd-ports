# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	sorl-thumbnail
PORTVERSION=	12.6.3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Sorl-thumbnail provides an easy way to generate image thumbnails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	PILLOW
OPTIONS_SINGLE=		IMAGELIB
OPTIONS_GROUP=		CACHING

OPTIONS_SINGLE_IMAGELIB=	GRAPHICSMAGICK IMAGEMAGICK PILLOW WAND
OPTIONS_GROUP_CACHING=		REDIS

DOCS_BUILD_DEPENDS=	${PY_SPHINX}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

GRAPHICSMAGICK_RUN_DEPENDS=	${LOCALBASE}/bin/gm:graphics/GraphicsMagick
IMAGEMAGICK_RUN_DEPENDS=	${LOCALBASE}/bin/convert:graphics/ImageMagick6
PILLOW_RUN_DEPENDS=		${PY_PILLOW}
REDIS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}
WAND_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}Wand>0:graphics/py-wand@${PY_FLAVOR}

GRAPHICSMAGICK_DESC=	Use GraphicsMagick for image processing (faster)
IMAGEMAGICK_DESC=	Use ImageMagick for image processing
PILLOW_DESC=		Use internal image processing
REDIS_DESC=		Use REDIS as Key Value Store
WAND_DESC=		Use Wand with ImageMagick

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
