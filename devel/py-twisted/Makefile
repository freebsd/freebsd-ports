# Created by: Johann Visagie <wjv@FreeBSD.org>

PORTNAME=	twisted
PORTVERSION=	22.1.0
CATEGORIES=	devel net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}incremental>=21.3.0:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>=0.8.0:devel/py-Automat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}constantly>=15.1:devel/py-constantly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=17.1.1:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=21.3.0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.4.2:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.5:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyHamcrest>=1.9.0:textproc/py-pyhamcrest@${PY_FLAVOR}

USES=		cpe python:3.7-3.10
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	twistedmatrix

NO_ARCH=	yes

OPTIONS_DEFINE=	CONCH HTTP2 SERIAL TLS
OPTIONS_DEFAULT=CONCH HTTP2 SERIAL TLS
CONCH_DESC=	Conch secure shell SSH
SERIAL_DESC=	Serial port extension

CONCH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}bcrypt>=3.0.0:security/py-bcrypt@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}cryptography>=2.6:security/py-cryptography@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3.0<4.1:www/py-h2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}priority1>=1.1.0<2.0:www/py-priority1@${PY_FLAVOR}
SERIAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR}
TLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=2.4:dns/py-idna@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}service_identity>=18.1.0:security/py-service_identity@${PY_FLAVOR}

# We need twisted.trial in PYTHONPATH
# twisted.conch tests depend on finding certain scripts in PATH
TEST_ENV=	PYTHONPATH=${WRKSRC}/src PATH=${STAGEDIR}/${PREFIX}/bin:$$PATH

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m twisted.trial -e twisted

.include <bsd.port.mk>
