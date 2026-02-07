PORTNAME=	azure-storage-common
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Storage Common Client Library for Python
WWW=		https://pypi.org/project/azure-storage-common/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=1.1.5:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
