# Created by: lbartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pointcloud
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases geography

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	270f3e112519.patch:-p1

MAINTAINER=	lbartoletti@FreeBSD.org
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

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/postgresql/pointcloud-${PORTVERSION:R}.so

.include <bsd.port.mk>
