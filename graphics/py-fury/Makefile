PORTNAME=	fury
DISTVERSION=	0.12.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free Unified Rendering in Python
WWW=		https://fury.gl/latest/index.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.4:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=17.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.4.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygltflib>=1.15.3:graphics/py-pygltflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR} \
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.5.3:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail with signal 10, see https://github.com/fury-gl/fury/issues/795

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

test-simple:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test-earth_8k.py

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
