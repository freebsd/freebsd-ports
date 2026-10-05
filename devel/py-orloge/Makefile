PORTNAME=	orloge
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OR log extractor
WWW=		https://github.com/pchtsp/orloge

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cpsat-logutils>=1.0.0:devel/py-cpsat-logutils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pchtsp

NO_ARCH=	yes

# tests as of 1.0.0: 2 passed

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

.include <bsd.port.mk>
