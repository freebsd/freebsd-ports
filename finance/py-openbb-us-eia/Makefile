PORTNAME=	openbb-us-eia
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: The U.S. Energy Information Administration is committed
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async-lru>=2:devel/py-async-lru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.0:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastmcp>=2.0:misc/py-fastmcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=2.0.1:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}curl-cffi>=0.7:ftp/py-curl-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
