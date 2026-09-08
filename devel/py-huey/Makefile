PORTNAME=	huey
DISTVERSION=	3.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Little task queue for Python
WWW=		https://huey.readthedocs.io \
		https://github.com/coleifer/huey

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

# tests as of 3.4.0: 243 passed, 171 skipped, 2 warnings in 20.76s

.include <bsd.port.mk>
