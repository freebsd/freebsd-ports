PORTNAME=	spatialite_gui
DISTVERSION=	2.1.0
PORTREVISION=	17
DISTVERSIONSUFFIX=	-beta1
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/spatialite-gui-sources/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Graphical User Interface (GUI) tool supporting SpatiaLite
WWW=		https://www.gaia-gis.it/fossil/spatialite_gui/index

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librasterlite2.so:graphics/librasterlite2 \
		libfreexl.so:textproc/freexl \
		libspatialite.so:databases/spatialite \
		libxlsxwriter.so:math/libxlsxwriter \
		libvirtualpg.so:databases/virtualpg \
		librttopo.so:devel/librttopo \
		libcurl.so:ftp/curl \
		libminizip.so:archivers/minizip \
		libproj.so:graphics/proj \
		libgeos_c.so:graphics/geos

USES=		compiler:c++11-lang gmake gnome iconv localbase:ldflags \
		pgsql pkgconfig sqlite
USE_WX=		3.0
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2

CPPFLAGS+=	`${WX_CONFIG} --cppflags`
LDFLAGS+=	${ICONV_LIB} `${WX_CONFIG} --libs` -lsqlite3
CONFIGURE_ARGS=	CFLAGS="${CFLAGS} ${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		--with-wxconfig=${WX_CONFIG}

.include <bsd.port.mk>
