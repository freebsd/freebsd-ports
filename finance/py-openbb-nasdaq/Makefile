PORTNAME=	openbb-nasdaq
DISTVERSION=	1.6.3
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Nasdaq extension for OpenBB
WWW=		https://github.com/OpenBB-finance/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async-lru>0:devel/py-async-lru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Nasdaq-Data-Link>=1.0.4:finance/py-Nasdaq-Data-Link@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=1.6.10:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-platform-api>=1.3.5:finance/py-openbb-platform-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}random-user-agent>=1.0.1:www/py-random-user-agent@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
