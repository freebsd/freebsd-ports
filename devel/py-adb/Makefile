PORTNAME=	adb
DISTVERSION=	1.3.0-9
DISTVERSIONSUFFIX=	-gd0be33c
CATEGORIES=	devel comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure-python implementation of ADB and Fastboot protocols

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libusb1>=1.0.16:devel/py-libusb1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	python-${PORTNAME}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
