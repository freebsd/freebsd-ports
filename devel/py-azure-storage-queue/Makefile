PORTNAME=	azure-storage-queue
PORTVERSION=	12.15.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	azure_storage_queue-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Azure Queue Storage Client Library for Python
WWW=		https://azure.github.io/azure-sdk-for-python/ \
		https://github.com/Azure/azure-sdk-for-python/tree/main/sdk/storage/azure-storage-queue \
		https://github.com/Azure/azure-sdk-for-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.30.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6.1:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
