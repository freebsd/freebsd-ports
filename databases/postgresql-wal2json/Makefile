PORTNAME=	wal2json
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	2_5
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	daniel@morante.net
COMMENT=	JSON output plugin for changeset extraction for PostgreSQL databases
WWW=		https://github.com/getsentry/wal2json/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pgsql:11-14
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	eulerto

MAKE_ARGS=	PG_CONFIG=${LOCALBASE}/bin/pg_config

PLIST_FILES=	lib/postgresql/wal2json.so

.include <bsd.port.mk>
