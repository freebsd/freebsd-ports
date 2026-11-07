PORTNAME=	agent-client-protocol
DISTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python implementation of the Agent Client Protocol (ACP)
WWW=		https://agentclientprotocol.github.io/python-sdk/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.7:devel/py-pydantic2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.21.0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
