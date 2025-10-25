PORTNAME=	azure-mgmt-core
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Management Core Library for Python
WWW=		https://pypi.org/project/azure-mgmt-core/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.24.0<2.0.0:devel/py-azure-core@${PY_FLAVOR}

USES=		azurepy python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
