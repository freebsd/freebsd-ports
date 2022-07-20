PORTNAME=	orage
PORTVERSION=	4.16.0
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Calendar application for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libical.so:devel/libical \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c++11-lang desktop-file-utils gettext gmake gnome \
		libtool pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	panel
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CFLAGS+=	-I${LOCALBASE}/include/libical
CONFIGURE_ARGS=	--enable-dbus

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify

.include <bsd.port.mk>
