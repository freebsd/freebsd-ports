# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	databases geography
MASTER_SITES=	http://download.osgeo.org/postgis/source/

MAINTAINER=	matt.trisoline@intermedix.com
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		geos:${PORTSDIR}/graphics/geos \
		json:${PORTSDIR}/devel/json-c
RUN_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

CONFLICTS=	postgis-1.*
LATEST_LINK=	postgis20

USE_GNOME=	libxml2
USE_PGSQL=	yes
USES=		gmake iconv perl5
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	build

OPTIONS_DEFINE=		LOADERGUI RASTER TOPOLOGY
OPTIONS_DEFAULT=	TOPOLOGY

LOADERGUI_DESC=	Enable shp2pgsql-gui
RASTER_DESC=	Build with raster support
TOPOLOGY_DESC=	Build with topology support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOADERGUI}
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gui
PLIST_SUB+=		LOADERGUI=""
.else
CONFIGURE_ARGS+=	--without-gui
PLIST_SUB+=		LOADERGUI="@comment "
.endif

.if ${PORT_OPTIONS:MRASTER}
.if ${OSVERSION} < 900033
BROKEN=			Raster suppport is broken on FreeBSD < 9.x
.endif
LIB_DEPENDS+=		gdal:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-raster --with-gdalconfig=${LOCALBASE}/bin/gdal-config
PLIST_SUB+=		RASTER=""
.else
CONFIGURE_ARGS+=	--without-raster
PLIST_SUB+=		RASTER="@comment "
.endif

.if ${PORT_OPTIONS:MTOPOLOGY}
CONFIGURE_ARGS+=	--with-topology
PLIST_SUB+=		TOPOLOGY=""
.else
CONFIGURE_ARGS+=	--without-topology
PLIST_SUB+=		TOPOLOGY="@comment "
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${GREP} -lR 'bin/bash' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e "s|/bin/bash|/bin/sh|"

pre-configure:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install: .SILENT
	${MKDIR} ${DATADIR}/tiger_2010
	(cd ${WRKSRC}/extras/tiger_geocoder/tiger_2010/ && ${COPYTREE_SHARE} \* ${DATADIR}/tiger_2010/ "! ( -name *\.orig -o -name *\.bak )" )
	${MKDIR} ${DATADIR}/utils
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} \* ${DATADIR}/utils/ "! ( -name *\.orig -o -name *\.bak )" )

.include <bsd.port.mk>
