PORTNAME=	chroma-hnswlib
DISTVERSION=	0.8.2
CATEGORIES=	databases python
#MASTER_SITES=	PYPI # PYPI has an older version than the one on GitHub, so we use GitHub instead (many other ports do the same)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast approximate nearest neighbor search library for Chroma
WWW=		https://github.com/chroma-core/chroma

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.10.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	chroma-core
GH_PROJECT=	hnswlib

MAKE_ENV=	HNSWLIB_NO_NATIVE=1

.include <bsd.port.mk>
