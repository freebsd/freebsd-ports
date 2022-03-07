# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	psycopg-c
PORTVERSION=	3.0.9
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL database adapter for Python - C optimization distribution

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		pgsql python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
