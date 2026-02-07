PORTNAME=	optimize-images
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI utility to reduce the file size of images
WWW=		https://github.com/victordomingos/optimize-images

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}piexif>=1.1.3:graphics/py-piexif@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=2.1.2:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}piexif>=1.1.3:graphics/py-piexif@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=2.1.2:devel/py-watchdog@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
