# New ports collection makefile for:	gmpc-libnotify
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-libnotify
PORTVERSION=	11.8.16
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A libnotify for gmpc

LIB_DEPENDS=	mpd.4:${PORTSDIR}/audio/libmpd \
		notify.4:${PORTSDIR}/devel/libnotify
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig glib20 gtk20 intltool
USE_GETTEXT=	yes

PLIST_FILES=	lib/gmpc/plugins/libnotifyplugin.la \
		lib/gmpc/plugins/libnotifyplugin.so
PLIST_DIRSTRY=	lib/gmpc/plugins lib/gmpc

.include <bsd.port.mk>
