# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-extraplaylist
PORTVERSION=	0.20.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Favorites plugin for gmpc

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_GNOME=	glib20 gtk20 libglade2 libxml2

PLIST_FILES=	lib/gmpc/plugins/libextraplaylist.so

.include <bsd.port.mk>
