# Created by: lbartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pointcloud
PORTVERSION=	1.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	LIDAR types for PostgreSQL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${LOCALBASE}/include/laz-perf/las.hpp:archivers/lazperf
LIB_DEPENDS=	libght.so:devel/libght

USES=		autoreconf compiler:c++0x gmake gnome pgsql
WANT_PGSQL=	server
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-lazperf=${LOCALBASE}
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pgpointcloud

.include <bsd.port.mk>
