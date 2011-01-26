# New ports collection makefile for:	gmpc-alarm
# Date created:		September 30 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-alarm
PORTVERSION=	0.20.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Alarm plugin for gmpc

LIB_DEPENDS=	mpd.3:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 intltool
USE_GETTEXT=	yes

.include <bsd.port.mk>
