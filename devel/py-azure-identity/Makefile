PORTNAME=	azure-identity
DISTVERSION=	1.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Identity Library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.0.0<2.0.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.1.4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal>=1.6.0<2.0.0:devel/py-msal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal-extensions>=0.3.0:devel/py-msal-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.6:devel/py-six@${PY_FLAVOR}

USES=		azurepy python:3.6+ zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
