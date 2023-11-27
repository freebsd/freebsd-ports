PORTNAME=	twisted
PORTVERSION=	23.8.0
PORTREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework written in Python
WWW=		https://twistedmatrix.com/ \
		https://github.com/twisted/twisted

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=22.5.0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.10.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=21.3.0:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=21.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>=0.8.0:devel/py-Automat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}constantly>=15.1:devel/py-constantly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=17.1.1:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=21.3.0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=5:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython-test-exception-raiser>=1.0.2<2:devel/py-cython-test-exception-raiser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=6.56:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyHamcrest>=2:textproc/py-pyhamcrest@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

CPE_VENDOR=	twistedmatrix

NO_ARCH=	yes

OPTIONS_DEFINE=	CONCH HTTP2 SERIAL TLS
OPTIONS_DEFAULT=CONCH HTTP2 SERIAL TLS
CONCH_DESC=	Conch secure shell SSH
SERIAL_DESC=	Serial port extension

CONCH_USE=		PYTHON=cryptography
CONCH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3.0<5.0:www/py-h2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}priority1>=1.1.0<2.0:www/py-priority1@${PY_FLAVOR}
SERIAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.0:comms/py-pyserial@${PY_FLAVOR}
TLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=2.4:dns/py-idna@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openssl>=21.0.0,1:security/py-openssl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}service-identity>=18.1.0:security/py-service-identity@${PY_FLAVOR}

# We need twisted.trial in PYTHONPATH
# twisted.conch tests depend on finding certain scripts in PATH
TEST_ENV=	PYTHONPATH=${WRKSRC}/src PATH=${STAGEDIR}/${PREFIX}/bin:$$PATH

post-patch:
	${GREP} -F -Rl TLS_METHOD ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's,TLS_METHOD,TLSv1_2_METHOD,'

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m twisted.trial -e twisted

.include <bsd.port.mk>
