# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.9.1
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/gdal/ \
		ftp://ftp.remotesensing.org/pub/gdal/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A translator library for geospatial data formats

CFLAGS+=	-fPIC ${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-libz=/usr --with-liblzma=yes --with-threads=yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

OPTIONS=	CFITSIO	"FITS support"			off \
		CURL	"Curl support"			off \
		ECW	"ECW & JPEG 2000 support"	off \
		EXPAT	"Expat support"			off \
		GEOS	"GEOS support"			off \
		GEOTIFF	"GeoTIFF support"		on \
		GIF	"GIF support"			on \
		HDF4	"HDF4 support"			off \
		HDF5	"HDF5 support"			off \
		JASPER	"JPEG 2000 support via jasper"	on \
		JPEG	"JPEG support"			on \
		KML	"KML support"			off \
		MYSQL	"MySQL support"			off \
		NETCDF	"NetCDF support"		off \
		ODBC	"ODBC support"			off \
		PGSQL	"PostgreSQL support"		off \
		PNG	"PNG support"			on \
		PROJ	"Projection support via proj"	off \
		SQLITE	"SQLite support"		off \
		TIFF	"External libtiff"		off \
		WEBP	"WebP support"			off \
		XERCES	"Xerces support"		off

HDF5_VER?=	18
NETCDF_VER?=	4
XERCES_PORT?=	textproc/xerces-c3

.include <bsd.port.options.mk>

.if defined(WITH_NETCDF) && (${NETCDF_VER} == "4")
WITH_HDF5=	yes
HDF5_VER=	18
.endif

.if defined(WITH_CFITSIO)
LIB_DEPENDS+=	cfitsio:${PORTSDIR}/astro/cfitsio
CONFIGURE_ARGS+=--with-cfitsio=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-cfitsio=no
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-curl=${LOCALBASE}/bin/curl-config
.else
CONFIGURE_ARGS+=--with-curl=no
.endif

.if defined(WITH_ECW)
LIB_DEPENDS+=	NCSEcw:${PORTSDIR}/graphics/libecwj2
CONFIGURE_ARGS+=--with-ecw=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-ecw=no
.endif

.if defined(WITH_EXPAT)
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=--with-expat=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-expat=no
.endif

.if defined(WITH_GEOS)
LIB_DEPENDS+=	geos:${PORTSDIR}/graphics/geos
CONFIGURE_ARGS+=--with-geos=${LOCALBASE}/bin/geos-config
.else
CONFIGURE_ARGS+=--with-geos=no
.endif

.if !defined(WITHOUT_GEOTIFF)
LIB_DEPENDS+=	geotiff:${PORTSDIR}/graphics/libgeotiff
CONFIGURE_ARGS+=--with-geotiff=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-geotiff=internal
.endif

.if !defined(WITHOUT_GIF)
LIB_DEPENDS+=	gif:${PORTSDIR}/graphics/giflib
CONFIGURE_ARGS+=--with-gif=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-gif=internal
.endif

.if defined(WITH_HDF4)
LIB_DEPENDS+=	mfhdf:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=--with-hdf4=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-hdf4=no
.endif

.if defined(WITH_HDF5)
.if (${NETCDF_VER} == "4")
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
.else
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/science/hdf5
.endif
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-hdf5=no
.endif

.if defined(WITH_ICONV)
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=--with-libiconv-prefix=no
.endif

.if !defined(WITHOUT_JASPER)
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--with-jasper=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-jasper=no
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-jpeg=internal
.endif

.if defined(WITH_KML)
LIB_DEPENDS+=	kmlbase:${PORTSDIR}/science/libkml
CONFIGURE_ARGS+=--with-libkml=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-libkml=no
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}/bin/mysql_config
.else
CONFIGURE_ARGS+=--with-mysql=no
.endif

.if defined(WITH_NETCDF)
.if (${NETCDF_VER} == "4")
LIB_DEPENDS+=	netcdf.7:${PORTSDIR}/science/netcdf4
.else
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
.endif
CONFIGURE_ARGS+=--with-netcdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-netcdf=no
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-odbc=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-odbc=no
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pg=${LOCALBASE}/bin/pg_config
.else
CONFIGURE_ARGS+=--with-pg=no
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-png=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-png=internal
.endif

.if defined(WITH_PROJ)
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
CONFIGURE_ARGS+=--with-static-proj4=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-static-proj4=no
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
CONFIGURE_ARGS+=--with-sqlite3=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-sqlite3=no
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--with-libtiff=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-libtiff=internal
.endif

.if defined(WITH_WEBP)
LIB_DEPENDS+=	webp:${PORTSDIR}/graphics/webp
CONFIGURE_ARGS+=--with-webp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-webp=no
.endif

.if defined(WITH_XERCES)
LIB_DEPENDS+=	xerces-c:${PORTSDIR}/${XERCES_PORT}
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-xerces=no
.endif

.if defined(WITH_HDF4) && defined(WITH_HDF5)
IGNORE=		you cannot use HDF4 with HDF5
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/GDALmake.opt ${DATADIR}/

.include <bsd.port.mk>
