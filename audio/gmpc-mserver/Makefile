# New ports collection makefile for:	gmpc-mserver
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-mserver
PORTVERSION=	0.19.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/gmpc-${PORTVERSION:C/\.0$//}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A plugin for gmpc that serves music.

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.5:${PORTSDIR}/ftp/curl \
		tag.6:${PORTSDIR}/audio/taglib \
		microhttpd:${PORTSDIR}/www/libmicrohttpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPEND=	gmpc:${PORTSDIR}/audio/gmpc

BROKEN=		fails to build

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_XORG=	x11
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
