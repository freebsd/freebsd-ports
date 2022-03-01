PORTNAME=	dnspython
PORTVERSION=	1.16.0
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1

MAINTAINER=	rm@FreeBSD.org
COMMENT=	DNS toolkit for Python - 1.x release

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:2.7 zip
USE_PYTHON=	autoplist concurrent cython distutils

NO_ARCH=	yes

PORTEXAMPLES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py xfr.py \
		zonediff.py

OPTIONS_DEFINE=			EXAMPLES PYCRYPTODOME
PYCRYPTODOME_DESC=		Enable pycryptodome (part of dnssec needs it)
PYCRYPTODOME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
