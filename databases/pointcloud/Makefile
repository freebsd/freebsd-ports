PORTNAME=	pointcloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	databases geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	LIDAR types for PostgreSQL
WWW=		https://github.com/pgpointcloud/pointcloud/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	liblazperf.so:archivers/lazperf

USES=		autoreconf compiler:c++0x gmake gnome pgsql
GNU_CONFIGURE=	yes
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	pgpointcloud
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-lazperf=${LOCALBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/postgresql/pointcloud-${DISTVERSION:R}.so

.include <bsd.port.mk>
