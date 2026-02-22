PORTNAME=	pg_auto_failover
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-

MAINTAINER=	pat@patmaddox.com
COMMENT=	Postgres extension for automated failover and high-availability
WWW=		https://pg-auto-failover.readthedocs.io

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

__MAX_PGSQL=	17
USES=		gmake pgsql:13-${__MAX_PGSQL}
WANT_PGSQL=	contrib server

USE_GITHUB=	yes
GH_ACCOUNT=	hapostgres

USE_RC_SUBR=	pg_auto_failover

CONFLICTS=	postgresql*-pg_auto_failover*

.include <bsd.port.pre.mk>

.if ${PGSQL_DEFAULT} > ${__MAX_PGSQL}
PGSQL_VER=	${__MAX_PGSQL}
.endif

.include <bsd.port.post.mk>
