# Created by: Loïc BARTOLETTI <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	http://download.osgeo.org/postgis/source/
PKGNAMESUFFIX=	23

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Geographic objects support for PostgreSQL databases

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:graphics/proj \
		libgeos.so:graphics/geos \
		libjson-c.so:devel/json-c
CONFLICTS=	postgis20-2.0.*  postgis-2.1.* postgis-22*

USES=		gettext gmake iconv:wchar_t libtool:keepla perl5 pgsql pkgconfig shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}
SHEBANG_FILES=	extensions/address_standardizer/*.pl raster/test/regress/*.pl \
		raster/test/regress/loader/*.pl regress/run_test.pl \
		utils/postgis_restore.pl.in utils/*.pl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build
WANT_PGSQL=	lib server

OPTIONS_DEFINE=		LOADERGUI RASTER TOPOLOGY SFCGAL ADDRSTD
OPTIONS_DEFAULT=	TOPOLOGY ADDRSTD
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

LOADERGUI_DESC=	Enable shp2pgsql-gui
RASTER_DESC=	Raster support
TOPOLOGY_DESC=	Topology support
SFCGAL_DESC=	Enable sfcgal
ADDRSTD_DESC=	Enable address standardizer

LOADERGUI_CONFIGURE_WITH=	gui
LOADERGUI_USE=	GNOME=gtk20
RASTER_USES=	alias
RASTER_CONFIGURE_WITH=	raster
RASTER_LIB_DEPENDS=		libgdal.so:graphics/gdal
RASTER_CONFIGURE_ON=	--with-gdalconfig=${LOCALBASE}/bin/gdal-config
TOPOLOGY_CONFIGURE_WITH=	topology
SFCGAL_LIB_DEPENDS=	libSFCGAL.so:databases/sfcgal
SFCGAL_CONFIGURE_ON=	--with-sfcgal=${LOCALBASE}/bin/sfcgal-config
SFCGAL_CONFIGURE_OFF=	--without-sfcgal
SFCGAL_IMPLIES=		RASTER
ADDRSTD_CONFIGURE_WITH=	address-standardizer
ADDRSTD_IMPLIES=	RASTER
ADDRSTD_LIB_DEPENDS=	libpcre.so:devel/pcre
ADDRSTD_VARS=		WANT_PGSQL+=contrib

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR 'bin/bash' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e "s|/bin/bash|/bin/sh|"
	@${GREP} -lR '/usr/bin/psql' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|/usr/bin/psql|${LOCALBASE}/bin/pgsql|"
	@${GREP} -lR '/usr/lib/postgresql/9.4/bin/psql' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|/usr/lib/postgresql/9.4/bin/psql|${LOCALBASE}/bin/pgsql|"
	@${GREP} -lR '/usr/share/postgresql/contrib' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|/usr/share/postgresql/contrib|${LOCALBASE}/share/postgresql/contrib|"
	@${GREP} -lR '/usr/share/postgresql/9.4/contrib' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|/usr/share/postgresql/9.4/contrib|${LOCALBASE}/share/postgresql/contrib/postgis-2.3|"

pre-configure:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/tiger_geocoder
	(cd ${WRKSRC}/extras/tiger_geocoder && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tiger_geocoder/ "! ( -name *\.orig -o -name *\.bak )" )
	${MKDIR} ${STAGEDIR}${DATADIR}/utils
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/utils/ "! ( -name *\.orig -o -name *\.bak -o -name Makefile -o -name *\.in -o -name uninstall_script )" )
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/shp2pgsql
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgsql2shp
.if ${PORT_OPTIONS:MLOADERGUI}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/shp2pgsql-gui
.else
	${RM} ${STAGEDIR}${PREFIX}/bin/shp2pgsql-gui
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblwgeom-2.3.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/postgis-2.3.so
.if ${PORT_OPTIONS:MTOPOLOGY}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/postgis_topology-2.3.so
.endif
.if ${PORT_OPTIONS:MRASTER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/raster2pgsql
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/rtpostgis-2.3.so
.endif
.if ${PORT_OPTIONS:MADDRSTD}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/address_standardizer-2.3.so
.endif

.include <bsd.port.post.mk>
