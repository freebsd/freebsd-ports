# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnspython
PORTVERSION=	2.0.0
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DNS toolkit for Python - 2.X branch

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ zip
USE_PYTHON=	autoplist cython distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES PYCRYPTODOME
PYCRYPTODOME_DESC=	Enable pycryptodome (part of dnssec needs it)
PYCRYPTODOME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR}

PORTEXAMPLES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py \
		xfr.py zonediff.py

post-install-EXAMPLES-on:
# examples
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} utest.py

.include <bsd.port.mk>
