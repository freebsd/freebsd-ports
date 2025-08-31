PORTNAME=	openslide-python
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	graphics
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to OpenSlide library for reading virtual slide images
WWW=		https://openslide.org \
		https://github.com/openslide/openslide-python

LICENSE=	LGPL21

RUN_DEPENDS=	openslide>0:graphics/openslide \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	openslide

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openslide/_convert.abi3.so

# tests as of 1.4.1: 59 passed in 11.97s

.include <bsd.port.mk>
