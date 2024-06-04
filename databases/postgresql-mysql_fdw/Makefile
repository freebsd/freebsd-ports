PORTNAME=	mysql_fdw
DISTVERSIONPREFIX=	REL-
DISTVERSION=	2_9_1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PostgreSQL foreign data wrapper for MySQL
WWW=		https://github.com/EnterpriseDB/mysql_fdw

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake mysql pgsql:11+
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

MAKE_ENV=	USE_PGXS=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/mysql_fdw.so

.include <bsd.port.mk>
