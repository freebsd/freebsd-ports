PORTNAME=	pg_net
PORTVERSION=	0.20.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	lukas.engelhardt@gmx.de
COMMENT=	PostgreSQL extension to trigger web services via postgresql
WWW=		https://supabase.github.io/pg_net/

LICENSE=	PostgreSQL

BUILD_DEPENDS=	curl:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	supabase

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_net.so

.include <bsd.port.mk>
