PORTNAME=	openbb-cftc
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: The mission of the Commodity Futures Trading Commission
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyarrow>=17:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diskcache>=5.6:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.0:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=2.0.1:textproc/py-xlrd@${PY_FLAVOR}
USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
