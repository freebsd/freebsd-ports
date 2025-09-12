PORTNAME=	pgactive
PORTVERSION=	2.1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Active-active replication extension for PostgreSQL
WWW=		http://github.com/aws/pgactive

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pgsql
WANT_PGSQL=	client server
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	aws

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgactive_dump
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgactive_init_copy
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgactive.so

.include <bsd.port.mk>
