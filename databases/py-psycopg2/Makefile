# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psycopg2
PORTVERSION=	2.8.4
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/doc/COPYING.LESSER

USES=		pgsql python
USE_PYTHON=	autoplist concurrent distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/psycopg2/_psycopg.so

.include <bsd.port.mk>
