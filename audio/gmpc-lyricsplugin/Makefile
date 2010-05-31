# New ports collection makefile for:	gmpc-lyricsplugin
# Date created:		September 14 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-lyricsplugin
PORTVERSION=	0.19.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A fetch lyrics gmpc plugin

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.6:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

.include <bsd.port.mk>
