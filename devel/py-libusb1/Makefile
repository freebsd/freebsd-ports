PORTNAME=	libusb1
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure-python wrapper for libusb-1.0

LICENSE=	LGPL21+

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyinstaller>=0:devel/py-pyinstaller@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
		@${PYTHON_CMD} -m unittest discover -vs ${TEST_WRKSRC}

.include <bsd.port.mk>
