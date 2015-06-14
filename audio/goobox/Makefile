# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/audio/goobox/Makefile 19823 2014-08-20 09:28:14Z gusi $

PORTNAME=	goobox
PORTVERSION=	3.3.2
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libdiscid.so:${PORTSDIR}/audio/libdiscid \
		libcoverart.so.0:${PORTSDIR}/audio/libcoverart \
		libmusicbrainz5.so:${PORTSDIR}/audio/libmusicbrainz5 \
		libbrasero-media3.so:${PORTSDIR}/sysutils/brasero \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

USES=		desktop-file-utils gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 gnomeprefix intlhack
USE_XORG=	x11
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Goobox.gschema.xml

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notification
.else
CONFIGURE_ARGS+=--disable-notification
.endif

.include <bsd.port.mk>
