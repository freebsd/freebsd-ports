# Created by: Randall Hopper
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A translator library for geospatial data formats

LICENSE=	MIT

OPTIONS_DEFINE=	CFITSIO CURL ECW EXPAT GEOS GEOTIFF GIF HDF5 ICONV JASPER \
		JPEG KML MYSQL NETCDF ODBC PGSQL PNG PROJ SQLITE TIFF WEBP \
		XERCES
OPTIONS_DEFAULT=GEOTIFF GIF JASPER JPEG PNG TIFF

CFLAGS+=	-fPIC ${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-libz=/usr --with-liblzma=yes --with-threads=yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE} ${PTHREAD_LIBS}
MAKE_JOBS_UNSAFE=	yes
MAKEFILE=	GNUmakefile
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

SLAVEDIRS=	graphics/p5-Geo-GDAL graphics/php-gdal graphics/py-gdal graphics/ruby-gdal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCFITSIO}
LIB_DEPENDS+=	cfitsio:${PORTSDIR}/astro/cfitsio
CONFIGURE_ARGS+=--with-cfitsio=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-cfitsio=no
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-curl=${LOCALBASE}/bin/curl-config
.else
CONFIGURE_ARGS+=--with-curl=no
.endif

.if ${PORT_OPTIONS:MECW}
LIB_DEPENDS+=	NCSEcw:${PORTSDIR}/graphics/libecwj2
CONFIGURE_ARGS+=--with-ecw=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-ecw=no
.endif

.if ${PORT_OPTIONS:MEXPAT}
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=--with-expat=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-expat=no
.endif

.if ${PORT_OPTIONS:MGEOS}
LIB_DEPENDS+=	geos:${PORTSDIR}/graphics/geos
CONFIGURE_ARGS+=--with-geos=${LOCALBASE}/bin/geos-config
.else
CONFIGURE_ARGS+=--with-geos=no
.endif

.if ${PORT_OPTIONS:MGEOTIFF}
LIB_DEPENDS+=	geotiff:${PORTSDIR}/graphics/libgeotiff
CONFIGURE_ARGS+=--with-geotiff=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-geotiff=internal
.endif

.if ${PORT_OPTIONS:MGIF}
LIB_DEPENDS+=	gif:${PORTSDIR}/graphics/giflib
CONFIGURE_ARGS+=--with-gif=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-gif=internal
.endif

.if ${PORT_OPTIONS:MHDF5}
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-hdf5=no
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}
USES+=		iconv
.else
CONFIGURE_ARGS+=--with-libiconv-prefix=no
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--with-jasper=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-jasper=no
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-jpeg=internal
.endif

.if ${PORT_OPTIONS:MKML}
LIB_DEPENDS+=	kmlbase:${PORTSDIR}/science/libkml
CONFIGURE_ARGS+=--with-libkml=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-libkml=no
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}/bin/mysql_config
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=--with-mysql=no
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=	netcdf.7:${PORTSDIR}/science/netcdf4
CONFIGURE_ARGS+=--with-netcdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-netcdf=no
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-odbc=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-odbc=no
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=--with-pg=${LOCALBASE}/bin/pg_config
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=--with-pg=no
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-png=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-png=internal
.endif

.if ${PORT_OPTIONS:MPROJ}
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
CONFIGURE_ARGS+=--with-static-proj4=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-static-proj4=no
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=--with-sqlite3=${LOCALBASE}
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=--with-sqlite3=no
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--with-libtiff=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-libtiff=internal
.endif

.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=	webp:${PORTSDIR}/graphics/webp
CONFIGURE_ARGS+=--with-webp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-webp=no
.endif

.if ${PORT_OPTIONS:MXERCES}
LIB_DEPENDS+=	xerces-c:${PORTSDIR}/textproc/xerces-c3
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-xerces=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/GDALmake.opt ${DATADIR}/

.include <bsd.port.mk>
