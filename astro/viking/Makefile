PORTNAME=	viking
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	lantw44@gmail.com
COMMENT=	Program to manage GPS data (tracks, waypoints, etc.)
WWW=		https://sourceforge.net/p/viking/wikiallura/Main_Page/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgeoclue-2.so:net/geoclue \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib \
		libnettle.so:security/nettle \
		liboauth.so:net/liboauth \
		libzip.so:archivers/libzip
RUN_DEPENDS=	gpsbabel:astro/gpsbabel

USES=		compiler:c++11-lib desktop-file-utils gettext gmake gnome \
		iconv localbase perl5 pkgconfig tar:bzip2 xorg
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack
USE_PERL5=	run
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README.md

OPTIONS_DEFINE=		DOCS GEOCACHES NLS GEOTAG GPSD MAPNIK MBTILES
OPTIONS_DEFAULT=	GEOTAG GPSD JOSM MAPNIK MBTILES

OPTIONS_MULTI=		EDITOR
OPTIONS_MULTI_EDITOR=	JOSM MERKAATOR

EDITOR_DESC=	OpenStreetMap editor
GEOCACHES_DESC=	GeoCaches Acquire support
GEOTAG_DESC=	Geotag support
GPSD_DESC=	Realtime GPS tracking
MAPNIK_DESC=	Mapnik support
MBTILES_DESC=	MBTiles support
JOSM_DESC=	Edit OpenStreetMap via JOSM
MERKAATOR_DESC=	Edit OpenStreetMap via Merkaartor

OPTIONS_SUB=	yes

GEOCACHES_CONFIGURE_ENABLE=	geocaches
GEOCACHES_SUB_FILES=	pkg-message

NLS_CONFIGURE_ENABLE=	nls

GEOTAG_LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2
GEOTAG_CONFIGURE_ENABLE=geotag

GPSD_LIB_DEPENDS=	libgps.so:astro/gpsd
GPSD_CONFIGURE_ENABLE=	realtime-gps-tracking

MAPNIK_LIB_DEPENDS=	libmapnik.so:graphics/mapnik
MAPNIK_CONFIGURE_ENV=	ac_cv_lib_icuuc_main=no # indirect
MAPNIK_CONFIGURE_ENABLE=	mapnik
MAPNIK_CPPFLAGS=	-I${LOCALBASE}/include/mapnik

MBTILES_USES=		sqlite
MBTILES_CONFIGURE_ENABLE=	mbtiles

JOSM_RUN_DEPENDS=	josm:astro/josm
MERKAATOR_RUN_DEPENDS=	merkaartor:astro/merkaartor

post-patch:
	@${REINPLACE_CMD} -e '/as_fn_error.*libicuuc/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/s| -g | |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|Science;|Education;Science;|' \
		${WRKSRC}/src/viking.desktop.in

post-install:
	${LN} -sf ../icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
