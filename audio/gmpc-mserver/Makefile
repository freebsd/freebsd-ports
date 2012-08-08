# New ports collection makefile for:	gmpc-mserver
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-mserver
PORTVERSION=	0.20.0
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lets you stream music files to your mpd that are not in your database

LIB_DEPENDS=	mpd.4:${PORTSDIR}/audio/libmpd \
		tag.1:${PORTSDIR}/audio/taglib \
		microhttpd:${PORTSDIR}/www/libmicrohttpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 libxml2
USE_GETTEXT=	yes

.include <bsd.port.mk>
