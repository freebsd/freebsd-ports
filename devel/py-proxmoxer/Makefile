PORTNAME=	proxmoxer
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Wrapper around the Proxmox REST API v2
WWW=		https://github.com/proxmoxer/proxmoxer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coveralls>0:devel/py-coveralls@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssh-wrapper>0:security/py-openssh-wrapper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TESTING_UNSAFE=	https://github.com/proxmoxer/proxmoxer/issues/195

NO_ARCH=	yes

.include <bsd.port.mk>
