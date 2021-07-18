PORTNAME=	azure-multiapi-storage
PORTVERSION=	0.6.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Storage Client Library with multi API version support

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=0:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.1.4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-core>=1.10.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrest>=0.6.18:net-mgmt/py-msrest@${PY_FLAVOR}

USES=		azurepy python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
