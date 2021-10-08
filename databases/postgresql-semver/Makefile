PORTNAME=	semver
PORTVERSION=	0.31.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@xanderio.de
COMMENT=	SemVer 2.0.0 compatible datatype for PostgreSQL database

LICENSE=	PostgreSQL

USES=		gmake pgsql
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	theory
GH_PROJECT=	pg-${PORTNAME}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
