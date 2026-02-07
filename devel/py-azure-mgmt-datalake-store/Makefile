PORTNAME=	azure-mgmt-datalake-store
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Data Lake Store Management Client Library for Python
WWW=		https://pypi.org/project/azure-mgmt-datalake-store/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrestazure>=0.4.27:net-mgmt/py-msrestazure@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-common>=1.1:www/py-azure-common@${PY_FLAVOR}

USES=		azurepy python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
