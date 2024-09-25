PORTNAME=	tds_fdw
PORTVERSION=	2.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL foreign data wrapper to connect to TDS databases
WWW=		https://github.com/tds-fdw/tds_fdw

LICENSE=	PostgreSQL

LIB_DEPENDS=	libsybdb.so:databases/freetds

USES=		gmake pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	tds-fdw

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/tds_fdw.so

.include <bsd.port.mk>
