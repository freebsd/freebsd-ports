PORTNAME=	psycopg2
PORTVERSION=	2.9.3
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/COPYING.LESSER

USES=		pgsql python:3.6+
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
