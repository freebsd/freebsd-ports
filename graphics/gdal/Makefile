# Created by: Randall Hopper
# $FreeBSD$

PORTNAME=	gdal
PORTVERSION=	1.11.2
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	http://download.osgeo.org/gdal/${PORTVERSION}/ \
		ftp://ftp.remotesensing.org/pub/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Translator library for raster geospatial data formats

LICENSE=	MIT

LIB_DEPENDS=	libgeotiff.so:${PORTSDIR}/graphics/libgeotiff \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

OPTIONS_DEFINE=	ARMADILLO CFITSIO CURL ECW EXPAT FREEXL GEOS GTA HDF5 ICONV \
		JASPER KML LIBXML2 MYSQL NETCDF ODBC OPENJPEG PCRE PGSQL PROJ \
		SQLITE WEBP XERCES
OPTIONS_DEFAULT=JASPER
OPTIONS_RADIO=	PDF
OPTIONS_RADIO_PDF=	PODOFO POPPLER
PCRE_DESC=	Regular expression support for SQLite

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--enable-static=yes \
		--with-geotiff=${LOCALBASE} \
		--with-gif=${LOCALBASE} \
		--with-jpeg=${LOCALBASE} \
		--with-libjson-c=${LOCALBASE} \
		--with-liblzma=yes \
		--with-libtiff=${LOCALBASE} \
		--with-libz=/usr \
		--with-png=${LOCALBASE} \
		--with-threads=yes \
		--without-libtool
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
USES=		gmake tar:xz

PLIST_SUB=	PORTVERSION=${PORTVERSION}
PORTDATA=	*

SLAVEDIRS=	graphics/p5-Geo-GDAL graphics/php-gdal graphics/py-gdal graphics/ruby-gdal

ARMADILLO_CONFIGURE_OFF=--with-armadillo=no
ARMADILLO_CONFIGURE_ON=	--with-armadillo=${LOCALBASE}
ARMADILLO_LIB_DEPENDS=	libarmadillo.so:${PORTSDIR}/math/armadillo
CFITSIO_CONFIGURE_OFF=	--with-cfitsio=no
CFITSIO_CONFIGURE_ON=	--with-cfitsio=${LOCALBASE}
CFITSIO_LIB_DEPENDS=	libcfitsio.so:${PORTSDIR}/astro/cfitsio
CURL_CONFIGURE_OFF=	--with-curl=no
CURL_CONFIGURE_ON=	--with-curl=${LOCALBASE}/bin/curl-config
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
ECW_CONFIGURE_OFF=	--with-ecw=no
ECW_CONFIGURE_ON=	--with-ecw=${LOCALBASE}
ECW_LIB_DEPENDS=	libNCSEcw.so:${PORTSDIR}/graphics/libecwj2
EXPAT_CONFIGURE_OFF=	--with-expat=no
EXPAT_CONFIGURE_ON=	--with-expat=${LOCALBASE}
EXPAT_LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
FREEXL_CONFIGURE_OFF=	--with-freexl=no
FREEXL_CONFIGURE_ON=	--with-freexl=${LOCALBASE}
FREEXL_LIB_DEPENDS=	libfreexl.so:${PORTSDIR}/textproc/freexl
GEOS_CONFIGURE_OFF=	--with-geos=no
GEOS_CONFIGURE_ON=	--with-geos=${LOCALBASE}/bin/geos-config
GEOS_LIB_DEPENDS=	libgeos.so:${PORTSDIR}/graphics/geos
GTA_CONFIGURE_OFF=	--with-gta=no
GTA_CONFIGURE_ON=	--with-gta=${LOCALBASE}
GTA_LIB_DEPENDS=	libgta.so:${PORTSDIR}/devel/libgta
HDF5_CONFIGURE_OFF=	--with-hdf5=no
HDF5_CONFIGURE_ON=	--with-hdf5=${LOCALBASE}
HDF5_LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5
ICONV_CONFIGURE_OFF=	--with-libiconv-prefix=no
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
ICONV_CPPFLAGS=		-I${LOCALBASE}/include
ICONV_LDFLAGS=		-L${ICONV_PREFIX}/lib ${ICONV_LIB}
ICONV_USES=		iconv
JASPER_CONFIGURE_OFF=	--with-jasper=no
JASPER_CONFIGURE_ON=	--with-jasper=${LOCALBASE}
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
KML_CONFIGURE_OFF=	--with-libkml=no
KML_CONFIGURE_ON=	--with-libkml=${LOCALBASE}
KML_LIB_DEPENDS=	libkmlbase.so:${PORTSDIR}/science/libkml
LIBXML2_CONFIGURE_OFF=	--with-xml2=no
LIBXML2_CONFIGURE_ON=	--with-xml2=${LOCALBASE}/bin/xml2-config
LIBXML2_LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
MYSQL_CONFIGURE_OFF=	--with-mysql=no
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_USE=		MYSQL=yes
NETCDF_CONFIGURE_OFF=	--with-netcdf=no
NETCDF_CONFIGURE_ON=	--with-netcdf=${LOCALBASE}
NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
ODBC_CONFIGURE_OFF=	--with-odbc=no
ODBC_CONFIGURE_ON=	--with-odbc=${LOCALBASE}
ODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
OPENJPEG_CONFIGURE_OFF=	--with-openjpeg=no
OPENJPEG_CONFIGURE_ON=	--with-openjpeg=${LOCALBASE}
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:${PORTSDIR}/graphics/openjpeg
PCRE_CONFIGURE_OFF=	--with-pcre=no
PCRE_CONFIGURE_ON=	--with-pcre=${LOCALBASE}
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PGSQL_CONFIGURE_OFF=	--with-pg=no
PGSQL_CONFIGURE_ON=	--with-pg=${LOCALBASE}/bin/pg_config
PGSQL_USES=		pgsql
PODOFO_CONFIGURE_OFF=	--with-podofo=no
PODOFO_CONFIGURE_ON=	--with-podofo=${LOCALBASE}
PODOFO_LIB_DEPENDS=	libpodofo.so:${PORTSDIR}/graphics/podofo
POPPLER_CONFIGURE_OFF=	--with-poppler=no
POPPLER_CONFIGURE_ON=	--with-poppler=${LOCALBASE}
POPPLER_LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler
PROJ_CONFIGURE_OFF=	--with-static-proj4=no
PROJ_CONFIGURE_ON=	--with-static-proj4=${LOCALBASE}
PROJ_LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj
SQLITE_CONFIGURE_OFF=	--with-sqlite3=no
SQLITE_CONFIGURE_ON=	--with-sqlite3=${LOCALBASE}
SQLITE_USE=		SQLITE=yes
WEBP_CONFIGURE_OFF=	--with-webp=no
WEBP_CONFIGURE_ON=	--with-webp=${LOCALBASE}
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp
XERCES_CONFIGURE_OFF=	--with-xerces=no
XERCES_CONFIGURE_ON=	--with-xerces=${LOCALBASE}
XERCES_LIB_DEPENDS=	libxerces-c.so:${PORTSDIR}/textproc/xerces-c3

post-patch:
	@${REINPLACE_CMD} -e 's|$$(INST_LIB)/pkgconfig|${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/GNUmakefile
# Cleanup bundled libraries
	@${RM} -fr ${WRKSRC}/frmts/gif/giflib/
	@${RM} -fr ${WRKSRC}/frmts/gtiff/libgeotiff/
	@${RM} -fr ${WRKSRC}/frmts/gtiff/libtiff/
	@${RM} -fr ${WRKSRC}/frmts/jpeg/libjpeg/
	@${RM} -fr ${WRKSRC}/frmts/jpeg/libjpeg12/
	@${RM} -fr ${WRKSRC}/frmts/png/libpng/
	@${RM} -fr ${WRKSRC}/frmts/zlib/
	@${RM} -fr ${WRKSRC}/ogr/ogrsf_frmts/geojson/libjson/

post-install:
	${INSTALL_DATA} ${WRKSRC}/libgdal.a ${STAGEDIR}${PREFIX}/lib/
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/gdalplugins/.keepme
	${INSTALL_DATA} ${WRKSRC}/GDALmake.opt ${STAGEDIR}${DATADIR}/
	-${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/libgdal.so.${PORTVERSION}

.include <bsd.port.mk>
