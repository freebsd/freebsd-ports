PORTNAME=	pg_failover_slots
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	PostgreSQL extension to keep logical replication slots on standbys
WWW=		https://github.com/EnterpriseDB/pg_failover_slots

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pgsql:11+
WANT_PGSQL=	lib server
USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

MAKE_ENV=	USE_PGXS=1

PLIST_FILES=	lib/postgresql/pg_failover_slots.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_failover_slots.so

.include <bsd.port.mk>
