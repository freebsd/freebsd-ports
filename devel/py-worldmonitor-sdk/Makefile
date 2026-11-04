PORTNAME=	worldmonitor-sdk
PORTVERSION=	0.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	worldmonitor_sdk-${PORTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Python client for the World Monitor global-intelligence API
WWW=		https://www.worldmonitor.app/docs/sdks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest discover -s tests

.include <bsd.port.mk>
