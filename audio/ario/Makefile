# New ports collection makefile for:	ario
# Date created:		Oct 07 2009
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	ario
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/ario-player/ario-player/${PORTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Ario is a GTK2 client for MPD

LICENSE=	GPLv2

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		curl:${PORTSDIR}/ftp/curl \
		notify:${PORTSDIR}/devel/libnotify \
		soup:${PORTSDIR}/devel/libsoup \
		tag_c:${PORTSDIR}/audio/taglib \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		mpdclient:${PORTSDIR}/audio/libmpdclient

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	AVAHI
AVAHI_DESC=	Zeroconf support (Avahi)
OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include <bsd.port.mk>
