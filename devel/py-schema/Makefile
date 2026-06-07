PORTNAME=	schema
DISTVERSION=	0.7.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple data validation library
WWW=		https://github.com/keleshev/schema

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

# tests as of 0.7.8: 118 passed, 1 warning in 0.54s

.include <bsd.port.mk>
