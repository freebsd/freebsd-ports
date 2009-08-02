# New ports collection makefile for:	vagalume
# Date created:	2008-06-14
# Whom:		Bernhard Fröhlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	vagalume
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL} \
		http://vagalume.igalia.com/files/source/
MASTER_SITE_SUBDIR=	pool/main/v/vagalume/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	decke@bluelife.at
COMMENT=	A GTK+-based client for the Last.fm online radio

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		curl.5:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:262
USE_GNOME=	pkgconfig gtk20
USE_GSTREAMER=	good mad
INSTALLS_ICONS=	yes

MAN1=		vagalume.1

OPTIONS=	DBUS "Build with DBUS support" on \
		TRAY "Build with tray icon and libnotify support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=--enable-dbus --enable-im-status
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
PLIST_SUB+=	DBUS=""
MAN1+=		vagalumectl.1
.else
CONFIGURE_ARGS+=--disable-dbus --disable-im-status
PLIST_SUB+=	DBUS="@comment "
.endif

.if !defined(WITHOUT_TRAY)
CONFIGURE_ARGS+=--enable-tray-icon
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libnotify.pc:${PORTSDIR}/devel/libnotify
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-tray-icon
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gconf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|serviceentrydir = @serviceentrydir@|serviceentrydir = ${PREFIX}/share/dbus-1/services|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
