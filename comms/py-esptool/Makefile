PORTNAME=	esptool
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
# Fix running test/test_espefuse_host.py on FreeBSD
PATCHFILES=	74c55a8ffce4347a11479b07d50ccca33e0c0b8d.patch:-p1
# The wheel package is only required when installing from pip
PATCHFILES+=	4b14df383c179d9b9bea48c269869e434de878fe.patch:-p1

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Utility to communicate with Espressif ESP8266 & ESP32 chips

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>0:security/py-ecdsa@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}bitstring>=3.1.6:devel/py-bitstring@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.1.4:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reedsolo>=1.5.3,<=1.5.4:devel/py-reedsolo@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	espressif
NO_ARCH=	yes

# test/test_espefuse_host.py calls the python command
# through subprocess Popen(), create an alias for it.
BINARY_ALIAS=		python=${PYTHON_CMD}

ESPTOOL_BAUDRATE?=	115200
ESPTOOL_CHIP?=		esp8266
ESPTOOL_SERIALPORT?=	/dev/ttyU0

do-test:
	@cd ${TEST_WRKSRC} && for test in \
		test/test_imagegen.py \
		test/test_espsecure.py \
		test/test_merge_bin.py \
		test/test_modules.py; \
		do ${SETENV} ${TEST_ENV} ${PYTHON_CMD} $${test}; done
	@cd ${TEST_WRKSRC} && for chip in \
		esp32 esp32s2 esp32s3beta2 esp32s3beta3 esp32c3; \
		do ${SETENV} ${TEST_ENV} ${PYTHON_CMD} \
		test/test_espefuse_host.py $${chip}; done
.if exists(${ESPTOOL_SERIALPORT})
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		${PYTHON_CMD} test/test_esptool.py \
		${ESPTOOL_SERIALPORT} ${ESPTOOL_CHIP} ${ESPTOOL_BAUDRATE}
.endif

.include <bsd.port.mk>
