PORTNAME=	meshcore
PORTVERSION=	2.2.11
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Base classes for communicating with meshcore companion radios
WWW=		https://github.com/meshcore-dev/meshcore_py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycayennelpp>=0:comms/py-cayennelpp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial-asyncio-fast>=0:comms/py-pyserial-asyncio-fast@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517
NO_ARCH=	yes

.include <bsd.port.mk>
