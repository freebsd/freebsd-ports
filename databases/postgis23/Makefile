# Created by: Loïc BARTOLETTI <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	2.3.10
PORTREVISION=	4
CATEGORIES=	databases geography
MASTER_SITES=	https://download.osgeo.org/postgis/source/
PKGNAMESUFFIX=	23

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Geographic objects support for PostgreSQL databases

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libgeos.so:graphics/geos \
		libjson-c.so:devel/json-c \
		libgdal.so:graphics/gdal

USES=		alias gettext gmake gnome iconv:wchar_t libtool:keepla \
		localbase perl5 pkgconfig pgsql:9.2-10 shebangfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE} NUMERICFLAGS=${PORTVERSION}
SHEBANG_FILES=	extensions/address_standardizer/*.pl raster/test/regress/*.pl \
		raster/test/regress/loader/*.pl regress/run_test.pl \
		utils/postgis_restore.pl.in utils/*.pl
WANT_PGSQL=	server

OPTIONS_DEFINE=	ADDRSTD LOADERGUI SFCGAL TOPOLOGY
OPTIONS_DEFAULT=ADDRSTD SFCGAL TOPOLOGY
OPTIONS_SUB=	yes

LOADERGUI_DESC=	Enable shp2pgsql-gui
TOPOLOGY_DESC=	Topology support
SFCGAL_DESC=	Enable sfcgal
ADDRSTD_DESC=	Enable address standardizer

CONFLICTS_INSTALL=	postgis20 postgis21 postgis22 postgis24 postgis25 postgis30

LOADERGUI_CONFIGURE_WITH=	gui
LOADERGUI_USE=			GNOME=gtk20
TOPOLOGY_CONFIGURE_WITH=	topology
SFCGAL_LIB_DEPENDS=		libSFCGAL.so:databases/sfcgal
SFCGAL_CONFIGURE_WITH=		sfcgal=${LOCALBASE}/bin/sfcgal-config
ADDRSTD_CONFIGURE_WITH=		address-standardizer
ADDRSTD_LIB_DEPENDS=		libpcre.so:devel/pcre
ADDRSTD_VARS=			WANT_PGSQL+=contrib

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblwgeom-2.3.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/*.so
	${MKDIR} ${STAGEDIR}${DATADIR}/tiger_geocoder
	(cd ${WRKSRC}/extras/tiger_geocoder && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tiger_geocoder/ "! ( -name *\.orig -o -name *\.bak )" )
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils/ "! ( -name *\.orig -o -name *\.bak -o -name Makefile -o -name *\.in -o -name uninstall_script )" )

.include <bsd.port.mk>
