PORTNAME=	libusb1
PORTVERSION=	3.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure-python wrapper for libusb-1.0
WWW=		https://github.com/vpelletier/python-libusb1

LICENSE=	LGPL21+

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyinstaller>=0:devel/py-pyinstaller@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>
