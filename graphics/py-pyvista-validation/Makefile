PORTNAME=	pyvista-validation
DISTVERSION=	0.5.4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyvista_validation-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Validate and standardize array-like input
WWW=		https://github.com/pyvista/pyvista-validation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.22.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.4:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}
TEST_ARGS=	--disable-plugin-autoload -p pytest_cov --no-cov --ignore=tests/typing

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyvista_validation/_fast*.so

pre-test:
	@${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pyvista_validation/_fast*.so \
		${WRKSRC}/pyvista_validation/

# tests as of 0.5.4: 2795 passed, 7 warnings in 6.69s

.include <bsd.port.mk>
