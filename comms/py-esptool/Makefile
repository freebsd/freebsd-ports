PORTNAME=	esptool
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5
PORTREVISION=	1
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Utility to communicate with Espressif ESP8266 & ESP32 chips
WWW=		https://github.com/espressif/esptool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.16.0:security/py-ecdsa@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}bitstring>=3.1.6,<4:devel/py-bitstring@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.1.4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reedsolo>=1.5.3,<=1.6.0:devel/py-reedsolo@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils pytest

GH_ACCOUNT=	espressif
NO_ARCH=	yes

# test/test_espefuse_host.py calls the python command
# through subprocess Popen(), create an alias for it.
BINARY_ALIAS=		python=${PYTHON_CMD}
TEST_ENV=		${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

ESPTOOL_BAUDRATE?=	115200
ESPTOOL_CHIP?=		esp8266
ESPTOOL_SERIALPORT?=	/dev/ttyU0

do-test:
	@cd ${TEST_WRKSRC} && for test in \
		test/test_imagegen.py \
		test/test_espsecure.py \
		test/test_merge_bin.py \
		test/test_image_info.py \
		test/test_modules.py; \
		do ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest $${test}; done
	@cd ${TEST_WRKSRC} && for chip in \
		esp32 esp32c2 esp32c3 esp32s2 esp32s3 esp32s3beta2 esp32h2beta1 esp32c6; \
		do ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		test/test_espefuse.py --chip $${chip}; done
.if exists(${ESPTOOL_SERIALPORT})
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} \
		${PYTHON_CMD} -m pytest test/test_esptool.py \
		--port ${ESPTOOL_SERIALPORT} \
		--chip ${ESPTOOL_CHIP} \
		--baud ${ESPTOOL_BAUDRATE}
.endif

.include <bsd.port.mk>
