PORTNAME=	openbb-bls
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: The Bureau of Labor Statistics' (BLS) Public Data
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=5:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.0:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
