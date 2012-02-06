# New ports collection makefile for:	gmpc-wikipedia
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmpc-wikipedia
PORTVERSION=	11.8.16
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Wikipedia info for gmpc

LIB_DEPENDS=	mpd.4:${PORTSDIR}/audio/libmpd \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPENDS=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig intltool glib20 gtk20
USE_GETTEXT=	yes

.include <bsd.port.mk>
