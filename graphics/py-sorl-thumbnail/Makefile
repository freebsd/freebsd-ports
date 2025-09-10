PORTNAME=	sorl-thumbnail
DISTVERSION=	12.11.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sorl_thumbnail-${DISTVERSION}

MAINTAINER=	ports@caomhin.org
COMMENT=	Sorl-thumbnail provides an easy way to generate image thumbnails
WWW=		https://github.com/jazzband/sorl-thumbnail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	PILLOW
OPTIONS_SINGLE=		IMAGELIB
OPTIONS_GROUP=		CACHING

# An PGMAGICK option would still be possible as well, but the ports tree does
# not yet have a py-pgmagick port.
OPTIONS_SINGLE_IMAGELIB=	GRAPHICSMAGICK IMAGEMAGICK PILLOW WAND
OPTIONS_GROUP_CACHING=		REDIS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

GRAPHICSMAGICK_RUN_DEPENDS=	${LOCALBASE}/bin/gm:graphics/GraphicsMagick
IMAGEMAGICK_USES=		magick:6,run
PILLOW_RUN_DEPENDS=		${PY_PILLOW}
REDIS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}
WAND_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}Wand>0:graphics/py-wand@${PY_FLAVOR}

GRAPHICSMAGICK_DESC=	Use GraphicsMagick for image processing (faster)
IMAGEMAGICK_DESC=	Use ImageMagick for image processing
PILLOW_DESC=		Use internal image processing
REDIS_DESC=		Use REDIS as Key Value Store
WAND_DESC=		Use Wand with ImageMagick

post-build-DOCS-on:
	${SETENV} PYTHONPATH=${WRKSRC} ${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} \
		-d ${WRKDIR} -b html ${WRKSRC}/docs ${WRKSRC}/build/sphinx/html

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
