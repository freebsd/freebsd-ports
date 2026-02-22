PORTNAME=	pg_auto_failover
DISTVERSION=	g20251117
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-
PKGNAMESUFFIX=	-devel

MAINTAINER=	pat@patmaddox.com
COMMENT=	Postgres extension for automated failover and high-availability
WWW=		https://pg-auto-failover.readthedocs.io

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

__MAX_PGSQL=	18
USES=		gmake pgsql:13-${__MAX_PGSQL}
WANT_PGSQL=	contrib server

USE_GITHUB=	yes
GH_ACCOUNT=	hapostgres
GH_TAGNAME=	5f31d4f5ef322b339d67cfd79d773e11f9e30fb0

USE_RC_SUBR=	pg_auto_failover

CONFLICTS=	postgresql*-pg_auto_failover*

.include <bsd.port.pre.mk>

.if ${PGSQL_DEFAULT} > ${__MAX_PGSQL}
PGSQL_VER=	${__MAX_PGSQL}
.endif

.include <bsd.port.post.mk>
