PORTNAME=	azure-mgmt-trafficmanager
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Traffic Manager Client Library for Python
WWW=		https://pypi.org/project/azure-mgmt-trafficmanager/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrest>=0.6.21:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-common>=1.1:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-core>=1.2.0<2.0.0:devel/py-azure-mgmt-core@${PY_FLAVOR}

USES=		azurepy python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
