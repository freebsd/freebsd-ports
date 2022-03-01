# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>

PORTNAME=	dnspython
PORTVERSION=	2.2.0
PORTEPOCH=	1
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DNS toolkit for Python

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist cython distutils

NO_ARCH=	yes

PORTEXAMPLES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py xfr.py \
		zonediff.py

OPTIONS_DEFINE=			EXAMPLES PYCRYPTODOME
PYCRYPTODOME_DESC=		Enable pycryptodome (part of dnssec needs it)
PYCRYPTODOME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} utest.py

.include <bsd.port.mk>
