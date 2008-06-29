# New ports collection makefile for:	vagalume
# Date created:	2008-06-14
# Whom:		Bernhard Fröhlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	vagalume
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
MASTER_SITE_SUBDIR=	pool/main/v/vagalume/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	decke@bluelife.at
COMMENT=	A GTK+-based client for the Last.fm online radio

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		curl.4:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_GNOME=	pkgconfig gtk20
USE_GSTREAMER=	good mad
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		vagalume.1

OPTIONS=	IMSTATUS "Build with IM status support" off \
		TRAY     "Build with tray icon and libnotify support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMSTATUS)
CONFIGURE_ARGS+=--enable-im-status
LIB_DEPEND+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.else
CONFIGURE_ARGS+=--disable-im-status
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

.include <bsd.port.post.mk>
