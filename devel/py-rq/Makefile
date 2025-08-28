PORTNAME=	rq
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Simple library for creating background jobs, and processing them
WWW=		https://python-rq.org

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=6.1.0:databases/py-redis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}rq1

NO_ARCH=	yes

.include <bsd.port.mk>
