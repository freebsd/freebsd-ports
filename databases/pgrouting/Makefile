# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pgrouting
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
PORTREVISION=	4
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Extension to PostGIS to provide geospatial routing functionality

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs\
		libCGAL.so:math/cgal \
		libgmp.so:math/gmp \
		liblwgeom.so:databases/postgis25

USES=		compiler:c++11-lib cmake localbase perl5 pgsql:9.1+ pkgconfig
WANT_PGSQL=	lib server
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
