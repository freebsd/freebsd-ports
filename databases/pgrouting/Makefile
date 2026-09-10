PORTNAME=	pgrouting
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Extension to PostGIS to provide geospatial routing functionality
WWW=		https://pgrouting.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++14-lang cmake localbase perl5 postgis pgsql pkgconfig
WANT_PGSQL=	lib server
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
