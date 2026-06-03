PORTNAME=	pg_net
PORTVERSION=	0.20.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	develuke@gmx.de
COMMENT=	PostgreSQL extension to trigger web services via postgresql
WWW=		https://supabase.github.io/pg_net/

LICENSE=	APACHE20

BUILD_DEPENDS=	curl:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	supabase

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_net.so

.include <bsd.port.mk>
