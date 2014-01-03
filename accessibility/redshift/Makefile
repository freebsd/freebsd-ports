# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redshift
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	accessibility
MASTER_SITES=	http://launchpad.net/redshift/trunk/${PORTVERSION}/+download/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Adjusts the color temperature of your screen

USES=		gmake pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=	--disable-wingdi

OPTIONS_DEFINE=	GNOME GUI NLS RANDR VIDMODE
OPTIONS_DEFAULT=	RANDR

GNOME_DESC=	GNOME clock support
GUI_DESC=	Tray icon
RANDR_DESC=	Support RANDR for changing colors
VIDMODE_DESC=	Support VIDMODE for changing colors (NVIDIA)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG} \
                --with-libintl-prefix=${LOCALBASE}
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MRANDR}
CONFIGURE_ARGS+=--enable-randr
USE_XORG=	xrandr
.else
CONFIGURE_ARGS+=--disable-randr
.endif

.if ${PORT_OPTIONS:MVIDMODE}
CONFIGURE_ARGS+=--enable-vidmode
.else
CONFIGURE_ARGS+=--disable-vidmode
.endif

.if ${PORT_OPTIONS:MGUI}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-gui
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk2>0:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_PKGNAMEPREFIX}xdg>0:${PORTSDIR}/devel/py-xdg
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
CONFIGURE_ARGS+=--enable-gnome-clock
BUILD_DEPENDS+=	glib>0:${PORTSDIR}/devel/glib20 \
		gconf2>0:${PORTSDIR}/devel/gconf2
RUN_DEPENDS+=	glib>0:${PORTSDIR}/devel/glib20 \
		gconf2>0:${PORTSDIR}/devel/gconf2
.else
CONFIGURE_ARGS+=--disable-gnome-clock
.endif

.include <bsd.port.mk>
