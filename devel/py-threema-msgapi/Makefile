PORTNAME=	threema-msgapi
PORTVERSION=	8.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	threema_gateway-${PORTVERSION}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Threema Gateway Message SDK for Python
WWW=		https://github.com/threema-ch/threema-msgapi-sdk-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.3:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libnacl>=1.5.2:security/py-libnacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logbook>=1.1.0:devel/py-logbook@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.10.10:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
