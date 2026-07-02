PORTNAME=	openbb-platform-api
DISTVERSION=	1.3.6
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: OpenBB Platform API: Launch script and widgets builder
WWW=		https://github.com/OpenBB-finance/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deepdiff>=8.6.2:devel/py-deepdiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=1.6.10:finance/py-openbb-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
