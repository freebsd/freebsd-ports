PORTNAME=	openbb-econometrics
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Econometrics Toolkit for OpenBB
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.0:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}linearmodels>=6:math/py-linearmodels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.14:math/py-statsmodels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}arch>=7.2:science/py-arch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11:science/py-scipy@${PY_FLAVOR}
USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
