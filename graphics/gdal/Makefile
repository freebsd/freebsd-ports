PORTNAME=	gdal
PORTVERSION=	3.11.3
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Translator library for raster geospatial data formats
WWW=		https://gdal.org/ \
		https://github.com/OSGeo/gdal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	fast_float>=0:math/fast_float \
		libertiff>=0:graphics/libertiff \
		libgeotiff>=1.5.0:graphics/libgeotiff \
		proj>=6,1:graphics/proj
LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff \
		libgif.so:graphics/giflib \
		libjson-c.so:devel/json-c \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libqhull_r.so:math/qhull \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++17-lang cpe iconv jpeg localbase pkgconfig ssl tar:xz

CMAKE_OFF=	BUILD_CSHARP_BINDINGS \
		BUILD_DOCS \
		BUILD_JAVA_BINDINGS \
		BUILD_PYTHON_BINDINGS \
		BUILD_TESTING \
		BUILD_VSIPRELOAD \
		CLANG_TIDY_ENABLED \
		CSHARP_MONO \
		ENABLE_DEFLATE64 \
		GDAL_ENABLE_HDF5_GLOBAL_LOCK  \
		GDAL_ENABLE_PLUGINS \
		GDAL_ENABLE_PLUGINS_NO_DEPS \
		GDAL_SET_INSTALL_RELATIVE_RPATH \
		GDAL_USE_INTERNAL_LIBS \
		GDAL_USE_GEOTIFF_INTERNAL \
		GDAL_USE_GIF_INTERNAL \
		GDAL_USE_JPEG12_INTERNAL \
		GDAL_USE_JPEG_INTERNAL \
		GDAL_USE_JSONC_INTERNAL \
		GDAL_USE_LERC_INTERNAL \
		GDAL_USE_LIBCSF_INTERNAL \
		GDAL_USE_OPENCAD \
		GDAL_USE_OPENCAD_INTERNAL \
		GDAL_USE_PNG_INTERNAL \
		GDAL_USE_PUBLICDECOMPWT \
		GDAL_USE_QHULL_INTERNAL \
		GDAL_USE_SHAPELIB \
		GDAL_USE_TIFF_INTERNAL \
		GDAL_USE_ZLIB_INTERNAL \
		HDFS_ENABLED \
		SWIG_REGENERATE_PYTHON \
		${CMAKE_OFF_${ARCH}}
CMAKE_OFF_armv7=GDAL_ENABLE_ARM_NEON_OPTIMIZATIONS
CMAKE_ON=	BUILD_APPS \
		BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		ENABLE_GNM \
		ENABLE_IPO \
		ENABLE_PAM \
		GDAL_AUTOLOAD_PLUGINS \
		GDAL_BUILD_OPTIONAL_DRIVERS \
		GDAL_HIDE_INTERNAL_SYMBOLS \
		GDAL_OBJECT_LIBRARIES_POSITION_INDEPENDENT_CODE \
		GDAL_SPLIT_EXPORTED_LIBS \
		GDAL_USE_CPL_MULTIPROC_PTHREAD \
		GDAL_USE_EXTERNAL_LIBS \
		GDAL_USE_GEOTIFF \
		GDAL_USE_GIF \
		GDAL_USE_ICONV \
		GDAL_USE_JPEG \
		GDAL_USE_JPEG12 \
		GDAL_USE_JSONC \
		GDAL_USE_LIBCSF \
		GDAL_USE_LIBLZMA \
		GDAL_USE_OPENSSL \
		GDAL_USE_PNG \
		GDAL_USE_QHULL \
		GDAL_USE_SHAPELIB_INTERNAL \
		GDAL_USE_TIFF \
		GDAL_USE_ZLIB \
		OGR_BUILD_OPTIONAL_DRIVERS \
		OGR_SQLITE_ALLOW_LOAD_EXTENSIONS \
		RENAME_INTERNAL_SHAPELIB_SYMBOLS \
		USE_CCACHE
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	osgeo

HEADER_FILES=	alg/gvgcpfit.h \
		alg/internal_qhull_headers.h \
		alg/thinplatespline.h\
		gcore/gdalexif.h \
		gcore/gdaljp2metadatagenerator.h \
		gcore/gdalsse_priv.h \
		gnm/gnm_priv.h \
		port/cpl_aws.h \
		port/cpl_cpu_features.h \
		port/cpl_google_cloud.h \
		port/cpl_odbc.h \
		port/cpl_sha1.h \
		port/cpl_sha256.h \
		port/cpl_vsil_curl_priv.h \
		port/cpl_worker_thread_pool.h

OPTIONS_DEFINE=	AEC ARMADILLO BLOSC BRUNSLI CFITSIO CRYPTOPP CURL DEFLATE ECW EXPAT FREEXL GEOS GTA HDF5 HEIF JXL KEA KML LERC LIBXML2 LZ4 MYSQL NETCDF ODBC OPENDRIVE OPENEXR OPENJPEG PCRE2 PGSQL QB3 RASTERLITE2 SFCGAL SPATIALITE SQLITE TILEDB WEBP XERCES ZSTD
OPTIONS_RADIO=	PDF
OPTIONS_RADIO_PDF=	PODOFO POPPLER
OPTIONS_DEFAULT=AEC CURL DEFLATE EXPAT FREEXL GEOS LERC LIBXML2 LZ4 OPENJPEG PCRE2 PGSQL POPPLER WEBP ZSTD \
		HDF5 KML NETCDF SPATIALITE SFCGAL SQLITE XERCES
OPTIONS_EXCLUDE_powerpc=	LERC
OPTIONS_EXCLUDE_powerpc64=	LERC
OPTIONS_SUB=	yes
AEC_DESC=	Adaptive entropy coding library
BLOSC_DESC=	Blosc support in Zarr driver
BRUNSLI_DESC=	Brunsli support via libbrunsli library
CRYPTOPP_DESC=	Cryptopp support
DEFLATE_DESC=	Faster deflate support via libdeflate library
KEA_DESC=	KEA format support
LERC_DESC=	LERC (Limited Error Raster Compression) support
OPENDRIVE_DESC=	OpenDRIVE format support
PCRE2_DESC=	Regular expression support for SQLite
QB3_DESC=	QB3 compression in MRF driver
RASTERLITE2_DESC=	RasterLite2 support
TILEDB_DESC=	TileDB support

AEC_CMAKE_BOOL=		GDAL_USE_LIBAEC
AEC_LIB_DEPENDS=	libaec.so:science/libaec
ARMADILLO_CMAKE_BOOL=	GDAL_USE_ARMADILLO
ARMADILLO_LIB_DEPENDS=	libarmadillo.so:math/armadillo
BLOSC_CMAKE_BOOL=	GDAL_USE_BLOSC
BLOSC_LIB_DEPENDS=	libblosc.so:archivers/c-blosc
BRUNSLI_CMAKE_BOOL=	GDAL_USE_BRUNSLI
BRUNSLI_LIB_DEPENDS=	libbrunslidec-c.so:graphics/brunsli
CFITSIO_CMAKE_BOOL=	GDAL_USE_CFITSIO
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
CRYPTOPP_CMAKE_BOOL=	GDAL_USE_CRYPTOPP
CRYPTOPP_LIB_DEPENDS=	libcryptopp.so:security/cryptopp
CURL_CMAKE_BOOL=	GDAL_USE_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
DEFLATE_CMAKE_BOOL=	GDAL_USE_DEFLATE
DEFLATE_LIB_DEPENDS=	libdeflate.so:archivers/libdeflate
ECW_CMAKE_BOOL=		GDAL_USE_ECW
ECW_LIB_DEPENDS=	libNCSEcw.so:graphics/libecwj2
EXPAT_CMAKE_BOOL=	GDAL_USE_EXPAT
EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
FREEXL_CMAKE_BOOL=	GDAL_USE_FREEXL
FREEXL_LIB_DEPENDS=	libfreexl.so:textproc/freexl
GEOS_CMAKE_BOOL=	GDAL_USE_GEOS
GEOS_LIB_DEPENDS=	libgeos.so:graphics/geos
GTA_CMAKE_BOOL=		GDAL_USE_GTA
GTA_LIB_DEPENDS=	libgta.so:devel/libgta
HDF5_CMAKE_BOOL=	GDAL_USE_HDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HEIF_CMAKE_BOOL=	GDAL_USE_HEIF
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
JXL_CMAKE_BOOL=		GDAL_USE_JXL GDAL_USE_JXL_THREADS
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
KEA_CMAKE_BOOL=		GDAL_USE_KEA
KEA_LIB_DEPENDS=	libkea.so:graphics/kealib
KML_CMAKE_BOOL=		GDAL_USE_LIBKML
KML_LIB_DEPENDS=	libkmlbase.so:science/libkml \
			liburiparser.so:net/uriparser
KML_USES=		minizip
LERC_CMAKE_BOOL=	GDAL_USE_LERC
LERC_LIB_DEPENDS=	libLerc.so:graphics/lerc
LIBXML2_CMAKE_BOOL=	GDAL_USE_LIBXML2
LIBXML2_LIB_DEPENDS=	libxml2.so:textproc/libxml2
LZ4_CMAKE_BOOL=		GDAL_USE_LZ4
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
MYSQL_CMAKE_BOOL=	GDAL_USE_MYSQL
MYSQL_USES=		mysql
NETCDF_CMAKE_BOOL=	GDAL_USE_NETCDF
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
ODBC_CMAKE_BOOL=	GDAL_USE_ODBC
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
OPENDRIVE_CMAKE_BOOL=	GDAL_USE_OPENDRIVE
OPENDRIVE_LDFLAGS=	-lpugixml
OPENDRIVE_LIB_DEPENDS=	libOpenDrive.so:graphics/libopendrive \
			libpugixml.so:textproc/pugixml
OPENEXR_CFLAGS=		-DInt64=uint64_t
OPENEXR_CMAKE_BOOL=	GDAL_USE_EXR
OPENEXR_LIB_DEPENDS=	libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr
OPENJPEG_BUILD_DEPENDS=	openjpeg>=2.1.0:graphics/openjpeg
OPENJPEG_CMAKE_BOOL=	GDAL_USE_OPENJPEG
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
PCRE2_CMAKE_BOOL=	GDAL_USE_PCRE2
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PGSQL_CMAKE_BOOL=	GDAL_USE_POSTGRESQL
PGSQL_USES=		pgsql
PODOFO_CMAKE_BOOL=	GDAL_USE_PODOFO
PODOFO_LIB_DEPENDS=	libpodofo.so:graphics/podofo
POPPLER_CMAKE_BOOL=	GDAL_USE_POPPLER
POPPLER_LIB_DEPENDS=	libpoppler.so:graphics/poppler
QB3_CMAKE_BOOL=		GDAL_USE_LIBQB3
QB3_LIB_DEPENDS=	libQB3.so:graphics/qb3
RASTERLITE2_CMAKE_BOOL=	GDAL_USE_RASTERLITE2
RASTERLITE2_LIB_DEPENDS=librasterlite2.so:graphics/librasterlite2
SFCGAL_CMAKE_BOOL=	GDAL_USE_SFCGAL
SFCGAL_LIB_DEPENDS=	libSFCGAL.so:databases/sfcgal
SPATIALITE_CMAKE_BOOL=	GDAL_USE_SPATIALITE
SPATIALITE_LIB_DEPENDS=	libspatialite.so:databases/spatialite
SQLITE_CMAKE_BOOL=	GDAL_USE_SQLITE3
SQLITE_USES=		sqlite
TILEDB_CMAKE_BOOL=	GDAL_USE_TILEDB
TILEDB_LIB_DEPENDS=	libtiledb.so:databases/tiledb
WEBP_CMAKE_BOOL=	GDAL_USE_WEBP
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
XERCES_CMAKE_BOOL=	GDAL_USE_XERCESC
XERCES_LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3
ZSTD_CMAKE_BOOL=	GDAL_USE_ZSTD
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
PLIST_SUB+=	BIGENDIAN="@comment "
.else
PLIST_SUB+=	BIGENDIAN=""
.endif

# Clean up bundled libraries
.if !defined(MAINTAINER_MODE)
EXTRACT_AFTER_ARGS=	--exclude ${DISTNAME}/alg/internal_libqhull \
			--exclude ${DISTNAME}/frmts/gif/giflib \
			--exclude ${DISTNAME}/frmts/gtiff/libgeotiff \
			--exclude ${DISTNAME}/frmts/jpeg/libjpeg \
			--exclude ${DISTNAME}/frmts/jpeg/libjpeg12 \
			--exclude ${DISTNAME}/frmts/png/libpng \
			--exclude ${DISTNAME}/frmts/zlib \
			--exclude ${DISTNAME}/ogr/ogrsf_frmts/geojson/libjson \
			--exclude ${DISTNAME}/third_party/fast_float \
			--exclude ${DISTNAME}/third_party/LercLib \
			--exclude ${DISTNAME}/third_party/libertiff \
			--no-same-owner --no-same-permissions
.else
post-patch:
	@${RM} -r ${WRKSRC}/alg/internal_libqhull/
	@${RM} -r ${WRKSRC}/frmts/gif/giflib/
	@${RM} -r ${WRKSRC}/frmts/gtiff/libgeotiff/
#	@${RM} -r ${WRKSRC}/frmts/gtiff/libtiff/ # tif_lerc.c, tif_lzw.c, tif_packbits.c
	@${RM} -r ${WRKSRC}/frmts/jpeg/libjpeg/
	@${RM} -r ${WRKSRC}/frmts/jpeg/libjpeg12/
	@${RM} -r ${WRKSRC}/frmts/png/libpng/
	@${RM} -r ${WRKSRC}/frmts/zlib/
	@${RM} -r ${WRKSRC}/ogr/ogrsf_frmts/geojson/libjson/
	@${RM} -r ${WRKSRC}/third_party/fast_float/
	@${RM} -r ${WRKSRC}/third_party/LercLib/
	@${RM} -r ${WRKSRC}/third_party/libertiff/
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/scripts/gdal-bash-completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${HEADER_FILES} ${STAGEDIR}${PREFIX}/include/
#	${INSTALL_DATA} ${WRKSRC}/libgdal.a ${STAGEDIR}${PREFIX}/lib/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdal.so

.include <bsd.port.mk>
