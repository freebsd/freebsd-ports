# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	cstore_fdw
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Columnar store for analytics with PostgreSQL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c

USES=		gmake pgsql:9.3+

SUB_FILES=	pkg-message

LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	citusdata

WANT_PGSQL=	server

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/cstore_fdw.so

.include <bsd.port.mk>
