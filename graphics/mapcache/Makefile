PORTNAME=		mapcache
DISTVERSION=		1.12.1
CATEGORIES=		graphics
MASTER_SITES=		http://download.osgeo.org/mapserver/

MAINTAINER=		wen@FreeBSD.org
COMMENT=		Server that implements tile caching to speed up access to WMS layers

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

LIB_DEPENDS=		libpng.so:graphics/png \
			libapr-1.so:devel/apr1 \
			libaprutil-1.so:devel/apr1 \
			libpixman-1.so:x11/pixman

USES=			cmake jpeg localbase
USE_LDCONFIG=		yes
CMAKE_ON=		WITH_OGR WITH_PIXMAN
CMAKE_OFF=		WITH_BERKELEY_DB

OPTIONS_DEFINE=		APACHE FASTCGI SQLITE MEMCACHE TIFF TIFF_WRITE \
			GEOTIFF PCRE GDAL GEOS
OPTIONS_DEFAULT=	APACHE FASTCGI SQLITE GEOS GDAL
OPTIONS_SUB=		yes

APACHE_DESC=		Native apache module
APACHE_USES=		apache
APACHE_CMAKE_BOOL=	WITH_APACHE
APACHE_CMAKE_ON=	-DAPACHE_INCLUDE_DIR=${LOCALBASE}/${APACHEINCLUDEDIR} \
			-DAPACHE_MODULE_DIR=${LOCALBASE}/${APACHEMODDIR}

FASTCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FASTCGI_CMAKE_BOOL=	WITH_FCGI

SQLITE_DESC=		Use sqlite as a cache backend
SQLITE_USES=		sqlite
SQLITE_CMAKE_BOOL=	WITH_SQLITE

MEMCACHE_DESC=		Use memcache as a cache backend
MEMCACHE_CMAKE_BOOL=	WITH_MEMCACHE

TIFF_DESC=		Use TIFFs as a cache backend
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=	WITH_TIFF

TIFF_WRITE_DESC=	Support for writable TIFF cache backends (implies TIFF)
TIFF_WRITE_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_WRITE_CMAKE_BOOL=	WITH_TIFF_WRITE_SUPPORT
TIFF_WRITE_IMPLIES=	TIFF

GEOTIFF_DESC=		GeoTIFF metadata creation for TIFF cache backends
GEOTIFF_LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff
GEOTIFF_CMAKE_BOOL=	WITH_GEOTIFF

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CMAKE_BOOL=	WITH_PCRE

GDAL_DESC=		GDAL library support
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
GDAL_CMAKE_BOOL=	WITH_GDAL WITH_OGR

GEOS_LIB_DEPENDS=	libgeos_c.so:graphics/geos
GEOS_CMAKE_BOOL=	WITH_GEOS

.include <bsd.port.mk>
