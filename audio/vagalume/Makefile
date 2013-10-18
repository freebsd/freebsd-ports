# Created by: Bernhard Fröhlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	vagalume
PORTVERSION=	0.8.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://vagalume.igalia.com/files/source/ \
		${MASTER_SITE_DEBIAN_POOL}
MASTER_SITE_SUBDIR=	pool/main/v/vagalume/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A GTK+-based client for the Last.fm online radio

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libcurl.so:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig desktop-file-utils
USE_GNOME=	gtk20
USE_GSTREAMER=	good mad gconf
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS TRAY NLS GCONF
OPTIONS_DEFAULT=	DBUS TRAY
OPTIONS_SUB=	NLS DBUS
TRAY_DESC=	Tray icon and libnotify support

.include <bsd.port.options.mk>

DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
DBUS_CONFIGURE_ON=	--enable-dbus --enable-im-status
DBUS_CONFIGURE_OFF=	--disable-dbus --disable-im-status

TRAY_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libnotify.pc:${PORTSDIR}/devel/libnotify
TRAY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
TRAY_CONFIGURE_ENABLE=	tray-icon

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|serviceentrydir = @serviceentrydir@|serviceentrydir = ${PREFIX}/share/dbus-1/services|' \
		${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|SUBDIRS = src po|SUBDIRS = src|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${CP} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
