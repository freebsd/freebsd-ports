# New ports collection makefile for:	ario
# Date created:		Oct 07 2009
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	ario
PORTVERSION=	1.4.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/ario-player/ario-player/${PORTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Ario is a GTK2 client for MPD

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		notify:${PORTSDIR}/devel/libnotify \
		soup:${PORTSDIR}/devel/libsoup22 \
		tag_c:${PORTSDIR}/audio/taglib \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		mpdclient:${PORTSDIR}/audio/libmpdclient
BUILD_DEPENDS=	mpd:${PORTSDIR}/audio/musicpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-avahi		# without this ario don't build
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack gnometarget
INSTALLS_ICONS=	yes

OPTIONS=	NLS "Use NLS" On

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=	yes
.endif

.include <bsd.port.mk>
