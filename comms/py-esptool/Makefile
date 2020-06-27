# $FreeBSD$

PORTNAME=	esptool
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Utility to communicate with Espressif ESP8266 & ESP32 chips

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaes>0:security/py-pyaes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	espressif
NO_ARCH=	yes

ESPTOOL_BAUDRATE?=	115200
ESPTOOL_CHIP?=		esp8266
ESPTOOL_SERIALPORT?=	/dev/ttyU0

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		--ignore test/test_esptool.py
.if exists(${ESPTOOL_SERIALPORT})
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} \
		${PYTHON_CMD} test/test_esptool.py \
		${ESPTOOL_SERIALPORT} ${ESPTOOL_CHIP} ${ESPTOOL_BAUDRATE}
.endif

.include <bsd.port.mk>
