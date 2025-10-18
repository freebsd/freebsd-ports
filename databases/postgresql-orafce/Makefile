PORTNAME=	orafce
DISTVERSIONPREFIX=	VERSION_
DISTVERSION=	4_16_0
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Oracle's compatibility functions and packages for PostgreSQL
WWW=		https://github.com/orafce/orafce

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.orafce

USES=		gmake pgsql

LLD_UNSAFE=	yes
WANT_PGSQL=	server

USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/orafce.so

.include <bsd.port.mk>
