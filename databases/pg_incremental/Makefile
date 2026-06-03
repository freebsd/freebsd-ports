PORTNAME=	pg_incremental
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Incremental Data Processing in PostgreSQL
WWW=		https://github.com/CrunchyData/pg_incremental

LICENSE=	PostgreSQL

RUN_DEPENDS=	pg_cron>=1.6.4:databases/pg_cron

USES=		gmake pgsql:10+

WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	CrunchyData

INSTALL_TARGET=	install-strip
MAKE_ARGS=	INSTALL="${INSTALL} -c"

.include <bsd.port.mk>
