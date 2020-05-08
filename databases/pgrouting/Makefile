# Created by: lbartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgrouting
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
DISTVERSIONSUFFIX=	-rc1
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Extension to PostGIS to provide geospatial routing functionality

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/share/postgresql/extension/postgis.control:databases/postgis30

USES=		compiler:c++14-lang cmake localbase perl5 pgsql:9.1+ pkgconfig
WANT_PGSQL=	lib server
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
