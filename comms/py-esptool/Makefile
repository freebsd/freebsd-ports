PORTNAME=	esptool
DISTVERSIONPREFIX=	v
DISTVERSION=	4.9.0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Utility to communicate with Espressif ESP8266 & ESP32 chips
WWW=		https://github.com/espressif/esptool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.16.0:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bitstring>=3.1.6:devel/py-bitstring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reedsolo>=1.5.3,<1.8:devel/py-reedsolo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intelhex>0:devel/py-intelhex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=3:devel/py-argcomplete@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent cryptography distutils pytest

GH_ACCOUNT=	espressif
NO_ARCH=	yes

# test/test_espefuse_host.py calls the python command
# through subprocess Popen(), create an alias for it.
BINARY_ALIAS=		python=${PYTHON_CMD}
TEST_ENV=		${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ENV+=		CRYPTOGRAPHY_OPENSSL_NO_LEGACY=1

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
		esp32 esp32c2 esp32c3 esp32c5 esp32c5beta3 esp32c6 esp32c61 \
		esp32h2 esp32h2beta1 esp32p4 esp32s2 esp32s3 esp32s3beta2 \
		esp32h21 esp32h4; \
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
