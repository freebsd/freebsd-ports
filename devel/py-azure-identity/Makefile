PORTNAME=	azure-identity
DISTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Identity Library for Python
WWW=		https://pypi.org/project/azure-identity/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.0.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal>=1.7.0<2.0.0:devel/py-msal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal-extensions>=0.3.0:devel/py-msal-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR}

USES=		azurepy python zip
USE_PYTHON=	autoplist concurrent cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
