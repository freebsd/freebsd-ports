PORTNAME=	msal
DISTVERSION=	1.10.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Authentication Library (MSAL) for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.0.0<3:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0.6<4:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
