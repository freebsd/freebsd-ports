# Created by: lbartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pointcloud
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	LIDAR types for PostgreSQL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${LOCALBASE}/include/laz-perf/las.hpp:archivers/lazperf
LIB_DEPENDS=	libght.so:devel/libght

USES=		cmake pgsql
WANT_PGSQL=	server
CMAKE_ARGS+=	-DWITH_TESTS:BOOL=FALSE
CFLAGS+=	-I${LOCALBASE}/include
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pgpointcloud

.include <bsd.port.mk>
