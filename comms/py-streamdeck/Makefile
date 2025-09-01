PORTNAME=	streamdeck
DISTVERSION=	0.9.7
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

USES=		dos2unix pytest python
USE_PYTHON=	autoplist pep517
PYTEST_ARGS=	test.py
# Note: PYTEST_ARGS isn't respected if pytest is placed in USE_PYTHON section

post-patch:
	${RM} ${WRKSRC}/src/StreamDeck/Transport/LibUSBHIDAPI.py.orig

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/test

.include <bsd.port.mk>
