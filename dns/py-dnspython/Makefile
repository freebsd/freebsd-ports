PORTNAME=	dnspython
DISTVERSION=	2.8.0
PORTEPOCH=	1
CATEGORIES=	dns python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DNS toolkit for Python
WWW=		https://www.dnspython.org/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent cython pep517 pytest

BINARY_ALIAS=	git=false
NO_ARCH=	yes

PORTEXAMPLES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py xfr.py \
		zonediff.py

OPTIONS_DEFINE=		DNSSEC DOH DOQ EXAMPLES IDNA TRIO
OPTIONS_DEFAULT=	DNSSEC DOH DOQ IDNA TRIO

DNSSEC_DESC=		DNSSEC Support
DOH_DESC=		DNS over HTTPS Support
DOQ_DESC=		DNS over QUIC Support
IDNA_DESC=		Internationalized Domain Names in Application Support
TRIO_DESC=		Concurrent async IO library support with TRIO backend

DNSSEC_USE=		PYTHON=cryptography
DOH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h2>=4.1.0:www/py-h2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httpcore>=1.0.0:www/py-httpcore@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httpx>=0.28.0:www/py-httpx@${PY_FLAVOR}
DOQ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioquic>=1.2.0:www/py-aioquic@${PY_FLAVOR}
IDNA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=3.10:dns/py-idna@${PY_FLAVOR}
TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.30:net/py-trio@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} utest.py

.include <bsd.port.mk>
