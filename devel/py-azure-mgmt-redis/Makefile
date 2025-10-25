PORTNAME=	azure-mgmt-redis
DISTVERSION=	14.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Redis Cache Management Client Library for Python
WWW=		https://pypi.org/project/azure-mgmt-redis/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrest>=0.7.1:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-common>=1.1:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-core>=1.3.2<2.0.0:devel/py-azure-mgmt-core@${PY_FLAVOR}

USES=		azurepy python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
