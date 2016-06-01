# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pgrouting
PORTVERSION=	2.2.3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Extension to PostGIS to provide geospatial routing functionality

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_system.so:devel/boost-libs\
		libCGAL.so:math/cgal \
		libgmp.so:math/gmp
RUN_DEPENDS=	${LOCALBASE}/share/postgresql/contrib/postgis-2.1/postgis.sql:databases/postgis21

USES=		compiler:c++11-lib cmake localbase pgsql:9.1+ pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting

.include <bsd.port.mk>
