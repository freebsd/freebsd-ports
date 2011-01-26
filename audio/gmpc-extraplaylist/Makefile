# New ports collection makefile for:	gmpc-extraplaylist
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-extraplaylist
PORTVERSION=	0.20.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A favorites plugin for gmpc

LIB_DEPENDS=	mpd.3:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig glib20 gtk20 libglade2 libxml2

PLIST_FILES=	lib/gmpc/plugins/libextraplaylist.la \
		lib/gmpc/plugins/libextraplaylist.so
PLIST_DIRSTRY=	lib/gmpc/plugins lib/gmpc

.include <bsd.port.mk>
