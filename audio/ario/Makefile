# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ario
PORTVERSION=	1.5.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF/ario-player/ario-player/${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Ario is a GTK2 client for MPD

LICENSE=	GPLv2

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libtag_c.so:${PORTSDIR}/audio/taglib \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libmpdclient.so:${PORTSDIR}/audio/libmpdclient

USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	AVAHI NLS
AVAHI_DESC=	Zeroconf support (Avahi)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-client.so:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gslist.h|glib.h|g ; \
		 s|glib/gkeyfile.h>|glib.h>|g' \
		${WRKSRC}/src/ario-util.h \
		${WRKSRC}/src/plugins/ario-plugin-info.c \
		${WRKSRC}/src/ario-profiles.h

.include <bsd.port.mk>
