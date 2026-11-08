PORTNAME=	openbb-sec
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: SEC extension for OpenBB
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diskcache>=5.6.3:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=5.2.1:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.13.0:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.1:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-platform-api>=2.0.1:finance/py-openbb-platform-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastmcp>=3.2.0:misc/py-fastmcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12:www/py-beautifulsoup4@${PY_FLAVOR}
USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
