# New ports collection makefile for:	gmpc-favorites
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-favorites
PORTVERSION=	0.15.5.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/gmpc-${PORTVERSION:C/\.0$//}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A favorites for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.5:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPEND=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

IGNORE=		does not work with new gmpc

.include <bsd.port.mk>
