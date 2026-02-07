PORTNAME=	msal-extensions
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Authentication Extensions for Python
WWW=		https://pypi.org/project/msal-extensions/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msal>=0.4.1<2.0.0:devel/py-msal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>=1.0<3:devel/py-portalocker@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
