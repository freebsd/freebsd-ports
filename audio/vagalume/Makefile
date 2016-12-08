# Created by: Bernhard Fröhlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	vagalume
PORTVERSION=	0.8.6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://vagalume.igalia.com/files/source/ \
		DEBIAN_POOL/pool/main/v/vagalume/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+-based client for the Last.fm online radio

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig desktop-file-utils
USE_GNOME=	gtk20 intltool
USE_GSTREAMER=	good mad gconf
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS TRAY NLS GCONF
OPTIONS_DEFAULT=	DBUS TRAY
OPTIONS_SUB=	NLS DBUS
TRAY_DESC=	Tray icon and libnotify support

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_ON=	--enable-dbus --enable-im-status
DBUS_CONFIGURE_OFF=	--disable-dbus --disable-im-status

TRAY_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libnotify.pc:devel/libnotify
TRAY_LIB_DEPENDS=	libnotify.so:devel/libnotify
TRAY_CONFIGURE_ENABLE=	tray-icon

NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=		gettext-tools

GCONF_USE=		GNOME=gconf2
GCONF_CONFIGURE_ENABLE=	gconf

post-patch:
	@${REINPLACE_CMD} -e 's|serviceentrydir = @serviceentrydir@|serviceentrydir = ${PREFIX}/share/dbus-1/services|' \
		${WRKSRC}/Makefile.in

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|SUBDIRS = src po|SUBDIRS = src|' \
		${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
