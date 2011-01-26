# New ports collection makefile for:	gmpc-lyrics
# Date created:		September 14 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-lyrics
PORTVERSION=	0.20.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Lyrics Provider plugin for gmpc

LIB_DEPENDS=	mpd.3:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig intltool glib20 gtk20 libxml2
USE_GETTEXT=	yes

PLIST_FILES=	lib/gmpc/plugins/lyricsplugin.la \
		lib/gmpc/plugins/lyricsplugin.so
PLIST_DIRSTRY=	lib/gmpc/plugins lib/gmpc

.include <bsd.port.mk>
