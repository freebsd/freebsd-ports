# Created by: David Le Brun <david@trucs.org>
# $FreeBSD$

PORTNAME=	viking
PORTVERSION=	1.7
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Program to manage GPS data (tracks, waypoints, etc.)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:devel/libpthread-stubs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgexiv2.so:graphics/gexiv2 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libgeoclue-2.so:net/geoclue \
		liboauth.so:net/liboauth
RUN_DEPENDS=	gpsbabel:astro/gpsbabel

USES=		compiler:c++11-lib gmake iconv desktop-file-utils perl5 pkgconfig tar:bzip2
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	cairo gnomedocutils gtk20 intlhack
USE_PERL5=	run
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=		DOCS GEOCACHES NLS GEOTAG GPSD MAPNIK MBTILES
OPTIONS_DEFAULT=	GEOTAG GPSD JOSM MAPNIK MBTILES

OPTIONS_MULTI=		OpenStreetMap-Editor
OPTIONS_MULTI_OpenStreetMap-Editor=	JOSM MERKAATOR

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
NLS_USES=		gettext

GEOTAG_LIB_DEPENDS=	libexif.so:graphics/libexif
GEOTAG_CONFIGURE_ENABLE=geotag

GPSD_LIB_DEPENDS=	libgps.so:astro/gpsd
GPSD_CONFIGURE_ENABLE=	realtime-gps-tracking

MAPNIK_LIB_DEPENDS=	libmapnik.so:graphics/mapnik
MAPNIK_CONFIGURE_ENV=	ac_cv_lib_icuuc_main=no # indirect
MAPNIK_CONFIGURE_ENABLE=	mapnik

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
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
