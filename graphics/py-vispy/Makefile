PORTNAME=	vispy
DISTVERSION=	0.17.0
CATEGORIES=	graphics science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance interactive 2D/3D data visualization library
WWW=		https://vispy.org/ \
		https://github.com/vispy/vispy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=3.0.0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-cython>0:devel/py-hatch-cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freetype-py>0:print/py-freetype-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hsluv>0:graphics/py-hsluv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>0:math/py-kiwisolver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython pep517

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/vispy/visuals/text/_sdf_cpu${PYTHON_TAG}.so

test-quick:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
