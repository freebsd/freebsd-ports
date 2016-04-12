# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ario
PORTVERSION=	1.5.1
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	SF/ario-player/ario-player/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ario is a GTK2 client for MPD

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libdbus-glib-1.so:devel/dbus-glib \
		libcurl.so:ftp/curl \
		libnotify.so:devel/libnotify \
		libsoup-2.4.so:devel/libsoup \
		libtag_c.so:audio/taglib \
		libunique-1.0.so:x11-toolkits/unique \
		libmpdclient.so:audio/libmpdclient

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gtk20 intltool
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	AVAHI NLS
AVAHI_DESC=	Zeroconf support (Avahi)

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=		gettext-tools

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gslist.h|glib.h|g ; \
		 s|glib/gkeyfile.h>|glib.h>|g' \
		${WRKSRC}/src/ario-util.h \
		${WRKSRC}/src/plugins/ario-plugin-info.c \
		${WRKSRC}/src/ario-profiles.h

.include <bsd.port.mk>
