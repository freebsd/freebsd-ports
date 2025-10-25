PORTNAME=	azure-keyvault-administration
DISTVERSION=	4.4.0b2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Key Vault Administration Client Library for Python
WWW=		https://pypi.org/project/azure-keyvault-administration/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=1.1:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-core>=1.24.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6.1:devel/py-isodate@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
