PORTNAME=	openslide-python
DISTVERSION=	1.3.1
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to OpenSlide library for reading virtual slide images
WWW=		https://openslide.org/

LICENSE=	LGPL21

RUN_DEPENDS=	openslide>0:graphics/openslide \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openslide/_convert${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
