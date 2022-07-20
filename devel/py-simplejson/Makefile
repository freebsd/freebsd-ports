PORTNAME=	simplejson
PORTVERSION=	3.17.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simple, fast, extensible JSON encoder/decoder

# dual-licensed under MIT and Academic Free License version 2.1
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe python:3.6+
CPE_VENDOR=	simplejson_project
USE_PYTHON=	autoplist concurrent distutils unittest

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
