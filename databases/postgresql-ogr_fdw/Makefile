PORTNAME=	ogr_fdw
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.7
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PostgreSQL foreign data wrapper for OGR
WWW=		https://github.com/pramsey/pgsql-ogr-fdw

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgdal.so:graphics/gdal

USES=		gmake pgsql:11+
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	pramsey
GH_PROJECT=	pgsql-ogr-fdw

MAKE_ENV=	USE_PGXS=1

PLIST_FILES=	bin/ogr_fdw_info \
		lib/postgresql/ogr_fdw.so \
		share/postgresql/extension/ogr_fdw--1.0--${PORTVERSION:R}.sql \
		share/postgresql/extension/ogr_fdw--${PORTVERSION:R}.sql \
		share/postgresql/extension/ogr_fdw.control

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ogr_fdw_info
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/ogr_fdw.so

.include <bsd.port.mk>
