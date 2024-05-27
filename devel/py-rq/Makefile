PORTNAME=	rq
PORTVERSION=	1.16.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple library for creating background jobs, and processing them
WWW=		https://python-rq.org

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=4.0.0:databases/py-redis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
