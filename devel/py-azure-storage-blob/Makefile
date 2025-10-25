PORTNAME=	azure-storage-blob
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Storage Blob Client Library for Python
WWW=		https://pypi.org/project/azure-storage-blob/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=1.1.5:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-common>=2.1:devel/py-azure-storage-common@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
