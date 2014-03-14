# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-lyricsplugin
PORTVERSION=	0.20.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A fetch lyrics gmpc plugin

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GNOME=	intltool glib20 gtk20 libxml2
USES=		gettext gmake pkgconfig

PLIST_FILES=	lib/gmpc/plugins/lyricspluginplugin.la \
		lib/gmpc/plugins/lyricspluginplugin.so
PLIST_DIRSTRY=	lib/gmpc/plugins lib/gmpc

.include <bsd.port.mk>
