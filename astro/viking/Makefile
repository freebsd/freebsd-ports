# Created by: David Le Brun <david@trucs.org>
# $FreeBSD$

PORTNAME=	viking
PORTVERSION=	1.3.2.1
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Program to manage GPS data (tracks, waypoints, etc.)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		curl:${PORTSDIR}/ftp/curl \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	gpsbabel:${PORTSDIR}/astro/gpsbabel

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	gnomedocutils gtk20
USE_PERL5_RUN=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	GEOTAG GPSD
OPTIONS_DEFAULT=	GEOTAG
GEOTAG_DESC=	Geotag support
GPSD_DESC=	Realtime GPS tracking

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
