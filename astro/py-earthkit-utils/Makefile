PORTNAME=	earthkit-utils
DISTVERSION=	1.0.2
CATEGORIES=	astro
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	earthkit_utils-${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Utilities for the Earthkit ecosystem
WWW=		https://github.com/ecmwf/earthkit-utils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}array-api-compat>=0:devel/py-array-api-compat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0:devel/py-pint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
