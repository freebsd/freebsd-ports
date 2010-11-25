# New ports collection makefile for:   redshift
# Date created:        Wed Nov 24 12:35:17 CST 2010
# Whom:                Mark Felder <feld@feld.me>
#
# $FreeBSD$
#

PORTNAME=	redshift
PORTVERSION=	1.6
CATEGORIES=	accessibility
MASTER_SITES=	http://launchpad.net/redshift/trunk/${PORTVERSION}/+download/

MAINTAINER=	feld@feld.me
COMMENT=	Adjusts the color temperature of your screen

FETCH_ARGS=	"-pRr"
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAN1=		redshift.1
MANCOMPRESSED=	no

CONFIGURE_ARGS+=--disable-wingdi --disable-gnome-clock --disable-gui

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

OPTIONS=	GUI	"Tray icon & location via Gnome clock" off \
		RANDR	"Support RANDR for changing colors" on \
		VIDMODE	"Support VIDMODE for changing colors (NVIDIA)" off

.include <bsd.port.options.mk>

.if defined(WITH_RANDR)
CONFIGURE_ARGS+=--enable-randr
USE_XORG=	xrandr
.else
CONFIGURE_ARGS+=--disable-randr
.endif

.if defined(WITH_VIDMODE)
CONFIGURE_ARGS+=--enable-vidmode
.else
CONFIGURE_ARGS+=--disable-vidmode
.endif

.if defined(WITH_GUI)
CONFIGURE_ARGS+=--enable-gui --enable-gnome-clock
RUN_DEPENDS+=	py-gtk2:${PORTSDIR}/x11-toolkits/py-gtk2 \
		py-xdg:${PORTSDIR}/devel/py-xdg
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--disable-gui --disable-gnome-clock
PLIST_SUB+=	GUI="@comment "
.endif

.include <bsd.port.mk>
