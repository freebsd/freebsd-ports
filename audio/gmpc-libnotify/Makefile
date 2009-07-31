# New ports collection makefile for:	gmpc-libnotify
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-libnotify
PORTVERSION=	0.18.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/download/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A libnotify for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.5:${PORTSDIR}/ftp/curl \
		notify.1:${PORTSDIR}/devel/libnotify
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

.include <bsd.port.mk>
