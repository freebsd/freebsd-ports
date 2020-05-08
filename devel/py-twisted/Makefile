# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twisted
PORTVERSION=	20.3.0
CATEGORIES=	devel net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}incremental>=16.10.1:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Automat>=0.3.0:devel/py-Automat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}constantly>=15.1:devel/py-constantly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=17.1.1:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>=16.10.1:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyHamcrest>=1.9.0:textproc/py-pyhamcrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.4.2:devel/py-zope.interface@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR}

USES=		python tar:bzip2
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	CONCH HTTP2 SERIAL TLS
OPTIONS_DEFAULT=CONCH HTTP2 SERIAL TLS
CONCH_DESC=	Conch secure shell SSH
SERIAL_DESC=	Serial port extension

CONCH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}bcrypt>=3.0.0:security/py-bcrypt@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}cryptography>=2.5:security/py-cryptography@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR}
HTTP2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=3.0<4.0:www/py-h2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}priority>=1.1.0<2.0:www/py-priority@${PY_FLAVOR}
SERIAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}serial>=3.0:comms/py-serial@${PY_FLAVOR}
TLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=0.6:dns/py-idna@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}service_identity>=18.1.0:security/py-service_identity@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m twisted.trial -e twisted

.include <bsd.port.mk>
