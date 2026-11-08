PORTNAME=	openbb-charting
DISTVERSION=	4.0.0
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenBB: Charting extension for OpenBB
WWW=		https://github.com/openbq-org/OpenBB

LICENSE=	AGPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.25:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openbb-core>=2.0.0:finance/py-openbb-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas-ta-openbb>=0.4.24:finance/py-pandas-ta-openbb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=6.3.1:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pywry>=2.0.4:www/py-pywry@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
