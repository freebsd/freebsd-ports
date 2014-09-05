# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	2.0.6
CATEGORIES=	databases geography
MASTER_SITES=	http://download.osgeo.org/postgis/source/
PKGNAMESUFFIX=	20

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geographic objects support for PostgreSQL databases

LICENSE=	GPLv2

LIB_DEPENDS=	libgeos.so:${PORTSDIR}/graphics/geos \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libproj.so:${PORTSDIR}/graphics/proj

CONFLICTS_INSTALL=	postgis-1.* postgis-2.1.*

OPTIONS_DEFINE=	LOADERGUI RASTER TOPOLOGY
OPTIONS_DEFAULT=TOPOLOGY
OPTIONS_SUB=	yes
LOADERGUI_DESC=	Enable shp2pgsql-gui
RASTER_DESC=	Build raster support
TOPOLOGY_DESC=	Build topology support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		gmake iconv libtool perl5 pgsql shebangfix
WANT_PGSQL=	server

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SHEBANG_FILES=	astyle.sh \
		extras/tiger_geocoder/tiger_2006andbefore/import/newdb.sh \
		extras/tiger_geocoder/tiger_2006andbefore/import/tigerimport.sh \
		extras/tiger_geocoder/tiger_2010/create_geocode.sh \
		extras/tiger_geocoder/tiger_2010/legacy_import/tiger2008/import_tiger_shps.sh \
		extras/tiger_geocoder/tiger_2010/upgrade_geocoder.sh \
		raster/test/regress/testgdalraster \
		utils/uninstall_script

#LOADERGUI_CONFIGURE_OFF=--without-gui
LOADERGUI_CONFIGURE_ON=	--with-gui
LOADERGUI_USE=		GNOME=gtk20
RASTER_CONFIGURE_OFF=	--without-raster
RASTER_CONFIGURE_ON=	--with-gdalconfig=${LOCALBASE}/bin/gdal-config --with-raster
RASTER_LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal
TOPOLOGY_CONFIGURE_WITH=topology

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MRASTER} && ${OSVERSION} < 900033
BROKEN=		Raster suppport is broken on FreeBSD < 9.x
.endif

post-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}/tiger_2010/
	(cd ${WRKSRC}/extras/tiger_geocoder/tiger_2010/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}/tiger_2010/)
	${MKDIR} ${STAGEDIR}/${DATADIR}/utils/
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}/utils/)
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/* ${STAGEDIR}/${PREFIX}/lib/*.so ${STAGEDIR}/${PREFIX}/lib/postgresql/*.so

.include <bsd.port.post.mk>
