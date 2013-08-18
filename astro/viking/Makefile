# Created by: David Le Brun <david@trucs.org>
# $FreeBSD$

PORTNAME=	viking
PORTVERSION=	1.4.2
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nemysis@FreeBSD.org
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

USES=		gmake iconv desktop-file-utils perl5 pkgconfig
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	gnomedocutils gtk20
USE_PERL5=	run
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=		DOCS NLS GEOTAG GPSD
OPTIONS_DEFAULT=	GEOTAG GPSD
GEOTAG_DESC=	Geotag support
GPSD_DESC=	Realtime GPS tracking

OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
GEOTAG_LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif
GEOTAG_CONFIGURE_ENABLE=geotag
GPSD_LIB_DEPENDS=	gps:${PORTSDIR}/astro/gpsd
GPSD_CONFIGURE_ENABLE=	realtime-gps-tracking

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/s| -g | |' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|Science;|Education;Science;|' ${WRKSRC}/src/viking.desktop.in

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
