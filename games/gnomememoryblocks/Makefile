# New ports collection makefile for:	gnomememoryblocks
# Date created:				10th July 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomememoryblocks
PORTVERSION=	0.1
CATEGORIES=	games gnome
# This should be ${MASTER_SITE_SOURCEFORGE} but doesn't appear to be
# linked in the right places at the moment
MASTER_SITES=	http://gnome-memblocks.sourceforge.net/downloads/ \
		ftp://gnome-memblocks.sourceforge.net/pub/gnome-memblocks/
DISTNAME=	gnome-memblocks-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
