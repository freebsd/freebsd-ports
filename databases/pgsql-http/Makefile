PORTNAME=	pgsql-http
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	lukas.engelhardt@gmx.de
COMMENT=	PostgreSQL extension to trigger web services
WWW=		https://github.com/pramsey/pgsql-http

LICENSE=	MIT

BUILD_DEPENDS=	curl:ftp/curl
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	pramsey

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/http.so

.include <bsd.port.mk>
