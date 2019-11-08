# $FreeBSD$

PORTNAME=	alarm-clock-applet
PORTVERSION=	0.3.4
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/alarm-clock/trunk/0.3.4/+download/

MAINTAINER=	iluxa@ex.ua
COMMENT=	Fully-featured alarm clock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libunique-1.0.so:x11-toolkits/unique \
		libgstreamer-1.0.so:multimedia/gstreamer1
BUILD_DEPENDS=	gnome-icon-theme>0:misc/gnome-icon-theme
RUN_DEPENDS=	gnome-icon-theme>0:misc/gnome-icon-theme

GNU_CONFIGURE=	yes
USES=		gettext-tools gmake gnome pkgconfig
USE_GNOME=	cairo gconf2 gtk20 intltool
USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes

GCONF_SCHEMAS=	alarm-clock.schemas

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
