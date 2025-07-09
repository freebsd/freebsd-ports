PORTNAME=	mapserver
DISTVERSION=	8.4.0
PORTREVISION=	3
CATEGORIES=	graphics www geography
MASTER_SITES=	https://download.osgeo.org/${PORTNAME}/ \
		https://github.com/MapServer/MapServer/releases/download/rel-${DISTVERSION:S|.|-|g}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	System for developing web-based GIS applications
WWW=		https://mapserver.org/

LICENSE=	MIT

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libgif.so:graphics/giflib \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libproj.so:graphics/proj

USES=		cmake compiler:c++11-lang cpe gnome iconv jpeg \
		localbase:ldflags
CPE_VENDOR=	osgeo
USE_GNOME=	libxml2

CMAKE_OFF=	WITH_CSHARP \
		WITH_JAVA \
		WITH_MYSQL \
		WITH_ORACLE_PLUGIN \
		WITH_ORACLESPATIAL \
		WITH_PIXMAN \
		WITH_RUBY \
		WITH_SVGCAIRO \
		WITH_THREAD_SAFETY \
		WITH_V8

CMAKE_ON=	CMAKE_SKIP_RPATH \
		WITH_FRIBIDI \
		WITH_GEOS \
		WITH_GIF \
		WITH_HARFBUZZ \
		WITH_ICONV \
		WITH_KML \
		WITH_LIBXML2 \
		WITH_OGCAPI \
		WITH_POSTGIS \
		WITH_SOS \
		WITH_WMS

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_MySQL:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_PIXMAN:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_SVGCairo:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_V8:BOOL=True

OPTIONS_DEFINE=		CAIRO CURL EXEMPI FASTCGI LIBRSVG2 PERL PHPNG \
			POSTGIS PROTOBUFC PYTHON WCS WFS XMLMAPFILE
OPTIONS_DEFAULT=	CAIRO CURL FASTCGI LIBRSVG2 POSTGIS PROTOBUFC WCS WFS
OPTIONS_SUB=		yes

EXEMPI_DESC=		XMP Metadata support
PHPNG_DESC=		PHPNG (SWIG) mapscript support
PROTOBUFC_DESC=		Protocol buffers support (req. for vector tiles)
WFS_DESC=               WFS Server support
WCS_DESC=               WCS Server support
XMLMAPFILE_DESC=	XML mapfile support

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_CMAKE_BOOL=	WITH_CAIRO
CAIRO_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Cairo:BOOL=True

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_BOOL=	WITH_CURL WITH_CLIENT_WFS WITH_CLIENT_WMS
CURL_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_CURL:BOOL=True

EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi
EXEMPI_CURL_BOOL=	WITH_EXEMPI
EXEMPI_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Exempi:BOOL=True

FASTCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FASTCGI_CMAKE_BOOL=	WITH_FCGI
FASTCGI_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_FCGI:BOOL=True

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_CMAKE_BOOL=	WITH_RSVG
LIBRSVG2_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_RSVG:BOOL=True
LIBRSVG2_IMPLIES=	CAIRO

PERL_BUILD_DEPEDNS=	swig:devel/swig
PERL_USES=		perl5
PERL_CMAKE_BOOL=	WITH_PERL

PHPNG_BUILD_DEPENDS=	swig:devel/swig
PHPNG_CMAKE_BOOL=	WITH_PHPNG

POSTGIS_USES=		pgsql
POSTGIS_CMAKE_BOOL=	WITH_POSTGIS
POSTGIS_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_PostgreSQL:BOOL=True

PROTOBUFC_LIB_DEPENDS=  libprotobuf-c.so:devel/protobuf-c
PROTOBUFC_CMAKE_BOOL=   WITH_PROTOBUFC
PROTOBUFC_CMAKE_OFF=    -DCMAKE_DISABLE_FIND_PACKAGE_ProtobufC:BOOL=True

PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WITH_PYTHON

WCS_CMAKE_BOOL=		WITH_WCS

WFS_CMAKE_BOOL=		WITH_WFS

XMLMAPFILE_USE=		GNOME=libxslt
XMLMAPFILE_CMAKE_BOOL=	WITH_XMLMAPFILE
XMLMAPFILE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_LibXslt:BOOL=True

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/legend ${STAGEDIR}${PREFIX}/bin/mapserver_legend
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mapserv ${STAGEDIR}${PREFIX}/bin/mapserver_mapserv
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/msencrypt ${STAGEDIR}${PREFIX}/bin/mapserver_msencrypt
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/scalebar ${STAGEDIR}${PREFIX}/bin/mapserver_scalebar
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/shptree ${STAGEDIR}${PREFIX}/bin/mapserver_shptree
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/shptreetst ${STAGEDIR}${PREFIX}/bin/mapserver_shptreetst
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/shptreevis ${STAGEDIR}${PREFIX}/bin/mapserver_shptreevis
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/sortshp ${STAGEDIR}${PREFIX}/bin/mapserver_sortshp
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/tile4ms ${STAGEDIR}${PREFIX}/bin/mapserver_tile4ms
	${INSTALL_LIB} ${BUILD_WRKSRC}/libmapserver.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib
	${RLN} libmapserver.so.${DISTVERSION} ${STAGEDIR}${PREFIX}/lib/libmapserver.so.2
	${RLN} libmapserver.so.2 ${STAGEDIR}${PREFIX}/lib/libmapserver.so

do-install-PYTHON-on:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/src/mapscript/python/mapscript.py ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/mapscript/python/_mapscript.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
