PORTNAME=	msal-extensions
DISTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Authentication Extensions for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msal>=0.4.1<2.0.0:devel/py-msal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>=1.0:devel/py-portalocker@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
