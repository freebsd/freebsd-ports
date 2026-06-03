PORTNAME=	msal-extensions
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	msal_extensions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Authentication Library extensions (MSAL EX)
WWW=		https://github.com/AzureAD/microsoft-authentication-extensions-for-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msal>=1.29<2:devel/py-msal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PORTALOCKER
OPTIONS_DEFAULT=PORTALOCKER
PORTALOCKER_DESC=	File locking via portalocker

PORTALOCKER_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}portalocker>=1.4<4:devel/py-portalocker@${PY_FLAVOR}

.include <bsd.port.mk>
