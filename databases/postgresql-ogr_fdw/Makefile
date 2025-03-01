PORTNAME=	ogr_fdw
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

PATCH_SITES=	https://github.com/pramsey/pgsql-ogr-fdw/commit/
PATCHFILES=	e22a6f9ac5f3f537c089ae39a1b96d1d1b7cc7c2.patch:-p1 \
		91731ce5fd51533590166e052f7c2b0831afca50.patch:-p1 \
		db95be3fddf9e0f2548e00ce12cfc0a75cb9d1d9.patch:-p1

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
