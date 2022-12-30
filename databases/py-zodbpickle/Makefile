PORTNAME=	zodbpickle
PORTVERSION=	2.6
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python pickling interface for ZODB
WWW=		https://github.com/zopefoundation/zodbpickle

LICENSE=	PSFL ZPL21
LICENSE_COMB=	multi

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
