# Created by: Bernhard Fröhlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	vagalume
PORTVERSION=	0.8.5
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://vagalume.igalia.com/files/source/ \
		${MASTER_SITE_DEBIAN_POOL}
MASTER_SITE_SUBDIR=	pool/main/v/vagalume/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A GTK+-based client for the Last.fm online radio

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GSTREAMER=	good mad gconf
INSTALLS_ICONS=	yes

MAN1=		vagalume.1

OPTIONS_DEFINE=	DBUS TRAY NLS GCONF
OPTIONS_DEFAULT=	DBUS TRAY
TRAY_DESC=	Tray icon and libnotify support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
CONFIGURE_ARGS+=--enable-dbus --enable-im-status
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS=""
MAN1+=		vagalumectl.1
.else
CONFIGURE_ARGS+=--disable-dbus --disable-im-status
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MTRAY}
CONFIGURE_ARGS+=--enable-tray-icon
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libnotify.pc:${PORTSDIR}/devel/libnotify
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-tray-icon
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

.include <bsd.port.mk>
