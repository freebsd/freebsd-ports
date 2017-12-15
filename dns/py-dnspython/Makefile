# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnspython
PORTVERSION=	1.15.0
CATEGORIES=	dns python
MASTER_SITES=	http://www.dnspython.org/kits/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	DNS toolkit for Python

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
USES=		python:2.7+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	EXAMPLES PYCRYPTO
PYCRYPTO_DESC=	Enable pycrypto (part of dnssec needs it)
PYCRYPTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${FLAVOR}

PORTEXAMPLES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py \
		xfr.py zonediff.py
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

post-install:
# examples
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
