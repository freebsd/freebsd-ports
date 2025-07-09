PORTNAME=	postgis
DISTVERSION=	3.3.8
PORTREVISION=	4
CATEGORIES=	databases geography
MASTER_SITES=	https://download.osgeo.org/postgis/source/
PKGNAMESUFFIX=	33

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Geographic objects support for PostgreSQL databases
WWW=		https://postgis.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libgeos.so:graphics/geos \
		libjson-c.so:devel/json-c \
		libgdal.so:graphics/gdal \
		libpcre2-8.so:devel/pcre2

USES=		alias compiler:c++14-lang cpe gmake gnome iconv:wchar_t libtool:keepla \
		localbase perl5 pkgconfig pgsql:11+ shebangfix
USE_GNOME=	libxml2
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE} NUMERICFLAGS=${PORTVERSION}
USE_CXXSTD=	c++14
SHEBANG_FILES=	extensions/address_standardizer/*.pl regress/run_test.pl \
		utils/postgis_restore.pl.in utils/*.pl
WANT_PGSQL=	server

OPTIONS_DEFINE=	ADDRSTD JSON LOADERGUI NLS PROTOBUF RASTER SFCGAL TOPOLOGY WAGYU
OPTIONS_DEFAULT=ADDRSTD JSON NLS PROTOBUF RASTER SFCGAL TOPOLOGY WAGYU
OPTIONS_SUB=	yes

ADDRSTD_DESC=	Enable address standardizer
JSON_DESC=	Enable JSON support
NLS_DESC=	Enable international language support
LOADERGUI_DESC=	Enable shp2pgsql-gui
PROTOBUF_DESC=	Enable protocol buffers
RASTER_DESC=	Enable raster support
SFCGAL_DESC=	Enable sfcgal
TOPOLOGY_DESC=	Topology support
WAGYU_DESC=	Enable WAGYU support

ADDRSTD_CONFIGURE_WITH=		address-standardizer
ADDRSTD_LIB_DEPENDS=		libpcre.so:devel/pcre
ADDRSTD_VARS=			WANT_PGSQL+=contrib
JSON_CONFIGURE_WITH=		json
JSON_LIB_DEPENDS=		libjson-c.so:devel/json-c
LOADERGUI_CONFIGURE_WITH=	gui
LOADERGUI_LIB_DEPENDS=		libprotobuf-c.so:devel/protobuf-c
LOADERGUI_USE=			GNOME=gtk20
LOADERGUI_USES=			desktop-file-utils
NLS_CONFIGURE_WITH=		nls
NLS_USES=			gettext
PROTOBUF_CONFIGURE_WITH=	protobuf
PROTOBUF_LIB_DEPENDS=		libprotobuf-c.so:devel/protobuf-c
SFCGAL_CONFIGURE_WITH=		sfcgal=${LOCALBASE}/bin/sfcgal-config
SFCGAL_LIB_DEPENDS=		libSFCGAL.so:databases/sfcgal
TOPOLOGY_CONFIGURE_WITH=	topology
WAGYU_CONFIGURE_WITH=		wagyu
RASTER_CONFIGURE_WITH=		raster

CONFLICTS_INSTALL=	postgis[0-9][0-9] # lib/postgresql/address_standardizer-3.so

VER=		${PORTVERSION:R}

PLIST_SUB=	PORTVERSION=${PORTVERSION}${DISTVERSIONSUFFIX} \
		VER=${VER}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} -e '/^#pragma GCC diagnostic/d' \
		${WRKSRC}/postgis/lwgeom_functions_basic.c \
		${WRKSRC}/postgis/lwgeom_geos.c
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgs* ${STAGEDIR}${PREFIX}/bin/rast* ${STAGEDIR}${PREFIX}/bin/shp*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/*.so
	${MKDIR} ${STAGEDIR}${DATADIR}/tiger_geocoder
	(cd ${WRKSRC}/extras/tiger_geocoder && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tiger_geocoder/ "! ( -name *\.orig -o -name *\.bak )" )
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils/ "! ( -name *\.orig -o -name *\.bak -o -name Makefile -o -name *\.in -o -name uninstall_script )" )

.include <bsd.port.post.mk>
