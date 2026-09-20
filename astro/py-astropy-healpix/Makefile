PORTNAME=	astropy-healpix
PORTVERSION=	2.0.1
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HEALPix algorithm for Astropy
WWW=		https://astropy-healpix.readthedocs.io/en/latest/ \
		https://github.com/astropy/astropy-healpix

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}extension-helpers>=1.3:astro/py-extension-helpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=6.1:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0,1:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-astropy>0:astro/py-pytest-astropy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

CFLAGS+=	-std=gnu11

# Work around astro/py-astropy vs NumPy 2.3 test-time import regressions.
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${FILESDIR}:${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME:S/-/_/}/tests
TEST_WRKSRC=	${WRKDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME:S/-/_/}/_core.*.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME:S/-/_/}/compiler_version.*.so

# tests as of 2.0.1: 125 passed, 1 skipped in 0.58s

.include <bsd.port.mk>
