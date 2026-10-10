PORTNAME=	openbb-yfinance
DISTVERSION=	2.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}-py3-none-any
EXTRACT_SUFX=	.whl

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Yfinance extension for OpenBB
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastmcp>=3:misc/py-fastmcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-charting>=4.0.0:finance/py-openbb-charting@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.1:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-platform-api>=2.0.1:finance/py-openbb-platform-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openbb-technical>=2.0.1:finance/py-openbb-technical@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pywry>=2.0.4:www/py-pywry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yfinance>=1.3:finance/py-yfinance@${PY_FLAVOR}

USES=		python
USE_PYTHON=	flavors

NO_ARCH=	yes
NO_BUILD=	yes

EXTRACT_CMD=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} ${PORTNAME:S/-/_/g} ${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} "${PORTNAME:S/-/_/g}-${DISTVERSION}.dist-info" ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
