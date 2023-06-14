PORTNAME=	psycopg2
PORTVERSION=	2.9.6
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL
WWW=		http://initd.org/psycopg/ \
		https://github.com/psycopg/psycopg2

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/COPYING.LESSER

USES=		pgsql python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
