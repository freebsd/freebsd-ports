PORTNAME=	pg_cron
PORTVERSION=	1.6.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Cron-based job scheduler for PostgreSQL that runs inside the database
WWW=		https://github.com/citusdata/pg_cron

LICENSE=	PostgreSQL

USES=		gmake pgsql:10+

WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	citusdata

INSTALL_TARGET=	install-strip
MAKE_ARGS=	INSTALL="${INSTALL} -c"

.include <bsd.port.mk>
