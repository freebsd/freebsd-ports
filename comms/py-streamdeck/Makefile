PORTNAME=	streamdeck
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Python library to control the Elgato Stream Deck
WWW=		https://github.com/abcminiuser/python-elgato-streamdeck

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libhidapi.so:comms/hidapi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=8.1.1:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.2.1:devel/py-pytest@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist pep517

post-patch:
	${RM} ${WRKSRC}/src/StreamDeck/Transport/LibUSBHIDAPI.py.orig

TEST_WRKSRC=	${WRKSRC}/test
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} pytest-${PYTHON_VER}
TEST_TARGET=	test.py

NO_ARCH=	yes

.include <bsd.port.mk>
