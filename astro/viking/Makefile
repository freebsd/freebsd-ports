# Created by: David Le Brun <david@trucs.org>
# $FreeBSD$

PORTNAME=	viking
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Program to manage GPS data (tracks, waypoints, etc.)

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		curl:${PORTSDIR}/ftp/curl \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	gpsbabel:${PORTSDIR}/astro/gpsbabel

USES=		iconv desktop-file-utils pkgconfig
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	gnomedocutils gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_RUN=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=		NLS GEOTAG GPSD
OPTIONS_DEFAULT=	GEOTAG
GEOTAG_DESC=	Geotag support
GPSD_DESC=	Realtime GPS tracking

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGEOTAG}
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
.else
CONFIGURE_ARGS+=	--disable-geotag
.endif

.if ${PORT_OPTIONS:MGPSD}
LIB_DEPENDS+=	gps:${PORTSDIR}/astro/gpsd
.else
CONFIGURE_ARGS+=	--disable-realtime-gps-tracking
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/s| -g | |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|Science;|Education;Science;|' ${WRKSRC}/src/viking.desktop.in

post-install:
# Port not install in figures jpg and png, this is cleaner as patch
	@${RM} -f ${PREFIX}/share/gnome/help/viking/C/figures/*
	@(cd ${WRKSRC}/help/C/figures && ${COPYTREE_SHARE} "*.jpg *.png" ${PREFIX}/share/gnome/help/viking/C/figures/)
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
