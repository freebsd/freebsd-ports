# New ports collection makefile for:	gmpc-qosd
# Date created:		September 14 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-qosd
PORTVERSION=	0.15.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/gmpc-${PORTVERSION}/plugins/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Q on Screen Display plugin for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.4:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc \
		xosd-config:${PORTSDIR}/misc/xosd
RUN_DEPEND=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehack

.include <bsd.port.mk>
