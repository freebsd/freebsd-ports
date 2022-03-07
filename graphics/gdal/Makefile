# Created by: Randall Hopper

PORTNAME=	gdal
PORTVERSION=	3.4.1
PORTREVISION=	7
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Translator library for raster geospatial data formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	libgeotiff>=1.5.0:graphics/libgeotiff \
		proj>=6,1:graphics/proj
LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff \
		libgif.so:graphics/giflib \
		libjson-c.so:devel/json-c \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libqhull_r.so:math/qhull \
		libtiff.so:graphics/tiff

OPTIONS_DEFINE=	ARMADILLO BRUNSLI CFITSIO CHARLS CRYPTOPP CURL DEFLATE DODS ECW EXPAT EXR FREEXL GEOS GTA HDF5 HEIF JASPER KML LERC LIBXML2 LZ4 MYSQL NETCDF ODBC OPENJPEG PCRE PCRE2 PGSQL RASTERLITE2 SFCGAL SPATIALITE SQLITE TILEDB WEBP XERCES ZSTD
OPTIONS_RADIO=	PDF
OPTIONS_RADIO_PDF=	PODOFO POPPLER
OPTIONS_DEFAULT=CURL EXPAT FREEXL GEOS JASPER LIBXML2 LZ4 OPENJPEG PCRE2 PGSQL POPPLER WEBP ZSTD \
		HDF5 KML NETCDF SPATIALITE SFCGAL SQLITE XERCES
OPTIONS_SUB=	yes
BRUNSLI_DESC=	Brunsli support via libbrunsli library
CHARLS_DESC=	JPEG-Lossless support via charls
CRYPTOPP_DESC=	Cryptopp support
DEFLATE_DESC=	Faster deflate support via libdeflate library
DODS_DESC=	DODS/OPeNDAP support
EXR_DESC=	EXR support via OpenEXR library
HEIF_DESC=	HEIF support via libheif library
LERC_DESC=	LERC (Limited Error Raster Compression) support
PCRE_DESC=	Regular expression support for SQLite
PCRE2_DESC=	Regular expression support for SQLite
RASTERLITE2_DESC=	RasterLite2 support
TILEDB_DESC=	TileDB support

USES=		compiler:c++14-lang cpe gmake iconv jpeg localbase pkgconfig ssl tar:xz

CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--datadir=${PREFIX}/share \
		--enable-static=yes \
		--with-cpp14 \
		--with-crypto=yes \
		--with-geotiff=yes \
		--with-gif=yes \
		--with-gnm=yes \
		--with-jpeg=yes \
		--with-libjson-c=yes \
		--with-liblzma=yes \
		--with-libtiff=yes \
		--with-libz=/usr \
		--with-pcidsk=internal \
		--with-pcraster=internal \
		--with-png=yes \
		--with-proj=yes \
		--with-qhull=yes \
		--with-threads=yes \
		--without-jpeg12 \
		--without-libtool \
		${ICONV_CONFIGURE_ARG}
GNU_CONFIGURE=	yes
LDFLAGS+=	${ICONV_LIB}
MAKEFILE=	GNUmakefile
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SLAVEDIRS=	graphics/p5-Geo-GDAL graphics/py-gdal

CPE_VENDOR=	osgeo

HEADER_FILES=	alg/gdalwarpkernel_opencl.h \
		alg/gvgcpfit.h \
		alg/internal_qhull_headers.h \
		alg/thinplatespline.h\
		gcore/gdalexif.h \
		gcore/gdaljp2metadatagenerator.h \
		gcore/gdalsse_priv.h \
		gnm/gnm_priv.h \
		port/cpl_aws.h \
		port/cpl_cpu_features.h \
		port/cpl_google_cloud.h \
		port/cpl_sha1.h \
		port/cpl_sha256.h \
		port/cpl_vsil_curl_priv.h \
		port/cpl_worker_thread_pool.h

ARMADILLO_CONFIGURE_OFF=--with-armadillo=no
ARMADILLO_CONFIGURE_ON=	--with-armadillo=${LOCALBASE}
ARMADILLO_LIB_DEPENDS=	libarmadillo.so:math/armadillo
BRUNSLI_CONFIGURE_WITH=	brunsli
BRUNSLI_LIB_DEPENDS=	libbrunslidec-c.so:graphics/brunsli
CFITSIO_CONFIGURE_WITH=	cfitsio
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
CHARLS_CONFIGURE_WITH=	charls
CHARLS_LIB_DEPENDS=	libcharls.so:graphics/charls
CRYPTOPP_CONFIGURE_OFF=	--with-cryptopp=no
CRYPTOPP_CONFIGURE_ON=	--with-cryptopp=${LOCALBASE}
CRYPTOPP_LIB_DEPENDS=	libcryptopp.so:security/cryptopp
CURL_CONFIGURE_OFF=	--with-curl=no
CURL_CONFIGURE_ON=	--with-curl=${LOCALBASE}/bin/curl-config
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
DEFLATE_CONFIGURE_WITH=	libdeflate
DEFLATE_LIB_DEPENDS=	libdeflate.so:archivers/libdeflate
DODS_CONFIGURE_OFF=	--with-dods-root=no
DODS_CONFIGURE_ON=	--with-dods-root=${LOCALBASE}
DODS_LIB_DEPENDS=	libdap.so:devel/libdap
ECW_CONFIGURE_WITH=	ecw
ECW_LIB_DEPENDS=	libNCSEcw.so:graphics/libecwj2
EXPAT_CONFIGURE_WITH=	expat
EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
EXR_CONFIGURE_WITH=	exr
EXR_LIB_DEPENDS=	libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr
EXR_CFLAGS=		-DInt64=uint64_t
FREEXL_CONFIGURE_WITH=	freexl
FREEXL_LIB_DEPENDS=	libfreexl.so:textproc/freexl
GEOS_CONFIGURE_OFF=	--with-geos=no
GEOS_CONFIGURE_ON=	--with-geos=${LOCALBASE}/bin/geos-config
GEOS_LIB_DEPENDS=	libgeos.so:graphics/geos
GTA_CONFIGURE_WITH=	gta
GTA_LIB_DEPENDS=	libgta.so:devel/libgta
HDF5_CONFIGURE_WITH=	hdf5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HEIF_CONFIGURE_WITH=	heif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
JASPER_CONFIGURE_WITH=	jasper
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
KML_CONFIGURE_WITH=	libkml
KML_LIB_DEPENDS=	libkmlbase.so:science/libkml
LERC_CONFIGURE_OFF=	--with-lerc=no
LERC_CONFIGURE_ON=	--with-lerc=${LOCALBASE}
LERC_LIB_DEPENDS=	libLerc.so:graphics/lerc
LIBXML2_CONFIGURE_OFF=	--with-xml2=no
LIBXML2_CONFIGURE_ON=	--with-xml2=yes
LIBXML2_LIB_DEPENDS=	libxml2.so:textproc/libxml2
LZ4_CONFIGURE_OFF=	--with-lz4=no
LZ4_CONFIGURE_ON=	--with-lz4=yes
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
MYSQL_CONFIGURE_OFF=	--with-mysql=no
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_USES=		mysql
NETCDF_CONFIGURE_WITH=	netcdf
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
ODBC_CONFIGURE_WITH=	odbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
OPENJPEG_BUILD_DEPENDS=	openjpeg>=2.1.0:graphics/openjpeg
OPENJPEG_CONFIGURE_WITH=openjpeg
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE2_CONFIGURE_WITH=	pcre2
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PGSQL_CONFIGURE_WITH=	pg
PGSQL_USES=		pgsql
PODOFO_CONFIGURE_WITH=	podofo
PODOFO_LIB_DEPENDS=	libpodofo.so:graphics/podofo
POPPLER_CONFIGURE_WITH=	poppler=${LOCALBASE}
POPPLER_LIB_DEPENDS=	libpoppler.so:graphics/poppler
RASTERLITE2_CONFIGURE_OFF=	--with-rasterlite2=no
RASTERLITE2_CONFIGURE_ON=	--with-rasterlite2=${LOCALBASE}
RASTERLITE2_LIB_DEPENDS=librasterlite2.so:graphics/librasterlite2
SFCGAL_CONFIGURE_OFF=	--with-sfcgal=no
SFCGAL_CONFIGURE_ON=	--with-sfcgal=${LOCALBASE}/bin/sfcgal-config
SFCGAL_LIB_DEPENDS=	libSFCGAL.so:databases/sfcgal
SPATIALITE_CONFIGURE_WITH=	spatialite
SPATIALITE_LIB_DEPENDS=	libspatialite.so:databases/spatialite
SQLITE_CONFIGURE_WITH=	sqlite3
SQLITE_USES=		sqlite
TILEDB_CONFIGURE_OFF=	--with-tiledb=no
TILEDB_CONFIGURE_ON=	--with-tiledb=${LOCALBASE}
TILEDB_LIB_DEPENDS=	libtiledb.so:databases/tiledb
WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
XERCES_CONFIGURE_WITH=	xerces
XERCES_LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3
ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/alg/internal_libqhull/
	@${RM} -r ${WRKSRC}/frmts/gif/giflib/
	@${RM} -r ${WRKSRC}/frmts/gtiff/libgeotiff/
	@${RM} -r ${WRKSRC}/frmts/gtiff/libtiff/
	@${RM} -r ${WRKSRC}/frmts/jpeg/libjpeg/
	@${RM} -r ${WRKSRC}/frmts/jpeg/libjpeg12/
	@${RM} -r ${WRKSRC}/frmts/png/libpng/
	@${RM} -r ${WRKSRC}/frmts/zlib/
	@${RM} -r ${WRKSRC}/ogr/ogrsf_frmts/geojson/libjson/
	@${RM} -r ${WRKSRC}/third_party/LercLib/

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/gdal-bash-completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${HEADER_FILES} ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libgdal.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/GDALmake.opt ${STAGEDIR}${DATADIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdal.so

.include <bsd.port.mk>
