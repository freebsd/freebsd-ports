PORTNAME=	pg_store_plans
DISTVERSION=	1.8
CATEGORIES=	databases

MAINTAINER=	joseph@2egos.de
COMMENT=	Enables Postgresql to store query execution plans in the Instance
WWW=		https://github.com/ossc-db/pg_store_plans

LICENSE=	Custom
LICENSE_NAME=	Custom
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	ossc-db

USES=		gmake pgsql:15+
WANT_PGSQL=	server
MAKE_ARGS=	USE_PGXS=YES

.include <bsd.port.mk>
