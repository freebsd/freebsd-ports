# Created by: Loïc BARTOLETTI <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	https://download.osgeo.org/postgis/source/
PKGNAMESUFFIX=	30

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Geographic objects support for PostgreSQL databases

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libgeos.so:graphics/geos \
		libjson-c.so:devel/json-c \
		libgdal.so:graphics/gdal

USES=		alias compiler:c++11-lang gmake gnome iconv:wchar_t libtool:keepla \
		localbase perl5 pkgconfig pgsql:9.5+ shebangfix
USE_GNOME=	libxml2
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE} NUMERICFLAGS=${PORTVERSION}
SHEBANG_FILES=	extensions/address_standardizer/*.pl raster/test/regress/*.pl \
		raster/test/regress/loader/*.pl regress/run_test.pl \
		utils/postgis_restore.pl.in utils/*.pl
WANT_PGSQL=	server

OPTIONS_DEFINE=	ADDRSTD JSON LOADERGUI NLS PROTOBUF RASTER SFCGAL TOPOLOGY WAGYU
OPTIONS_DEFAULT=ADDRSTD JSON NLS PROTOBUF RASTER SFCGAL TOPOLOGY WAGYU
OPTIONS_SUB=	yes

ADDRSTD_DESC=	Enable address standardizer
JSON_DESC=	Enable JSON support
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
LOADERGUI_USE=			GNOME=gtk20
NLS_CONFIGURE_WITH=		nls
NLS_USES=			gettext
PROTOBUF_CONFIGURE_WITH=	protobuf
PROTOBUF_LIB_DEPENDS=		libprotobuf-c.so:devel/protobuf-c
SFCGAL_CONFIGURE_WITH=		sfcgal=${LOCALBASE}/bin/sfcgal-config
SFCGAL_LIB_DEPENDS=		libSFCGAL.so:databases/sfcgal
TOPOLOGY_CONFIGURE_WITH=	topology
WAGYU_CONFIGURE_WITH=		wagyu

CONFLICTS_INSTALL=	postgis20 postgis21 postgis22 postgis23 postgis24 postgis25

VER=		${PORTVERSION:R}

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		VER=${VER}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} -e '/^#pragma GCC diagnostic/d' \
		${WRKSRC}/postgis/lwgeom_functions_basic.c \
		${WRKSRC}/postgis/lwgeom_geos.c
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/*.so
	${MKDIR} ${STAGEDIR}${DATADIR}/tiger_geocoder
	(cd ${WRKSRC}/extras/tiger_geocoder && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tiger_geocoder/ "! ( -name *\.orig -o -name *\.bak )" )
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils/ "! ( -name *\.orig -o -name *\.bak -o -name Makefile -o -name *\.in -o -name uninstall_script )" )

.include <bsd.port.post.mk>
