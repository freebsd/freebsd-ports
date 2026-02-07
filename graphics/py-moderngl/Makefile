PORTNAME=	moderngl
DISTVERSION=	5.12.0
PORTREVISION=	1
CATEGORIES=	graphics
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ModernGL: High performance rendering for Python 3
WWW=		https://moderngl.readthedocs.io/en/latest/ \
		https://github.com/moderngl/moderngl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}glcontext>=3.0.0:graphics/py-glcontext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR}
TEST_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.1:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 test fails due to path mismatch, see https://github.com/pytest-dev/pytest/issues/11142

USE_GITHUB=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/moderngl/mgl${PYTHON_TAG}.so

# tests as of 5.12.0: 1 failed, 322 passed, 37 skipped in 24.63s, see https://github.com/moderngl/moderngl/issues/722

.include <bsd.port.mk>
