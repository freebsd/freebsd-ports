# New ports collection makefile for:	gmpc-qosd
# Date created:		September 14 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-qosd
PORTVERSION=	0.15.5.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/gmpc-${PORTVERSION:C/\.0$//}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Q on Screen Display plugin for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.5:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc \
		xosd-config:${PORTSDIR}/misc/xosd
RUN_DEPEND=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

IGNORE=		does not work with new gmpc

.include <bsd.port.mk>
