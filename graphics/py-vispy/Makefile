PORTNAME=	vispy
DISTVERSION=	0.15.2
CATEGORIES=	graphics science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance interactive 2D/3D data visualization library
WWW=		https://vispy.org/ \
		https://github.com/vispy/vispy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freetype-py>0:print/py-freetype-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hsluv>0:graphics/py-hsluv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiwisolver>0:math/py-kiwisolver@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython3 pep517 pytest # pytest crashes on some tests, and then keeps restarting

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/vispy/visuals/text/_sdf_cpu${PYTHON_TAG}.so

.include <bsd.port.mk>
