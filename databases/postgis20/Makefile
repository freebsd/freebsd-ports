# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	2.0.7
PORTREVISION=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://download.osgeo.org/postgis/source/
PKGNAMESUFFIX=	20

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geographic objects support for PostgreSQL databases

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgeos.so:graphics/geos \
		libjson-c.so:devel/json-c \
		libproj.so:graphics/proj

CONFLICTS_INSTALL=	postgis- postgis22- postgis23-

OPTIONS_DEFINE=	LOADERGUI NLS RASTER TOPOLOGY
OPTIONS_DEFAULT=TOPOLOGY
OPTIONS_SUB=	yes
LOADERGUI_DESC=	Enable shp2pgsql-gui
RASTER_DESC=	Raster support
TOPOLOGY_DESC=	Topology support

PORTSCOUT=	limit:^2.0.[0-9]*

CONFIGURE_ARGS=	--with-geosconfig=${LOCALBASE}/bin/geos-config \
		--with-jsondir=${LOCALBASE} \
		--with-pgconfig=${LOCALBASE}/bin/pg_config \
		--with-projdir=${LOCALBASE} \
		--with-xml2config=${LOCALBASE}/bin/xml2-config \
		${ICONV_CONFIGURE_ARG} ${ICONV_CONFIGURE_BASE}
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		gmake iconv:wchar_t libtool perl5 pgsql pkgconfig shebangfix
WANT_PGSQL=	server

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SHEBANG_FILES=	astyle.sh \
		extras/tiger_geocoder/tiger_2006andbefore/import/newdb.sh \
		extras/tiger_geocoder/tiger_2006andbefore/import/tigerimport.sh \
		extras/tiger_geocoder/tiger_2010/create_geocode.sh \
		extras/tiger_geocoder/tiger_2010/legacy_import/tiger2008/import_tiger_shps.sh \
		extras/tiger_geocoder/tiger_2010/upgrade_geocoder.sh \
		raster/test/regress/testgdalraster \
		utils/postgis_restore.pl.in \
		utils/uninstall_script

LOADERGUI_CONFIGURE_WITH=	gui
LOADERGUI_USE=		GNOME=gtk20
NLS_CONFIGURE_WITH=	gettext
NLS_USES=		gettext
RASTER_CONFIGURE_OFF=	--without-raster
RASTER_CONFIGURE_ON=	--with-gdalconfig=${LOCALBASE}/bin/gdal-config --with-raster
RASTER_LIB_DEPENDS=	libgdal.so:graphics/gdal
TOPOLOGY_CONFIGURE_WITH=topology

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/utils/ ${STAGEDIR}${DATADIR}/tiger_2010/
	cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils/
	cd ${WRKSRC}/extras/tiger_geocoder/tiger_2010/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tiger_2010/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so ${STAGEDIR}${PREFIX}/lib/postgresql/*.so

.include <bsd.port.mk>
