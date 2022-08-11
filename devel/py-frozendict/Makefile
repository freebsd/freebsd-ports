PORTNAME=	frozendict
PORTVERSION=	2.3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		https://github.com/Marco-Sulla/python-frozendict/releases/download/v${PORTVERSSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Immutable dictionary implementation for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
