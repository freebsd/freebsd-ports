PORTNAME=	sdm_modbus
DISTVERSION=	0.7.0
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	Library for Eastron SDM single or three phase kWh meters
WWW=		https://github.com/nmakel/sdm_modbus

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymodbus>=2.0:comms/py-pymodbus@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

PORTDOCS=	*

.include <bsd.port.mk>
