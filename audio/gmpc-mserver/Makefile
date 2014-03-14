# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gmpc-mserver
PORTVERSION=	0.20.0
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lets you stream music files to your mpd that are not in your database

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd \
		libtag.so:${PORTSDIR}/audio/taglib \
		libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	glib20 gtk20 libxml2
USES=		gettext gmake pathfix pkgconfig

.include <bsd.port.mk>
