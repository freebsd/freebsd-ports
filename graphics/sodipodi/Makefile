# New ports collection makefile for:   sodipodi
# Date created:        28 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sodipodi
PORTVERSION=	0.18
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		glade.3:${PORTSDIR}/devel/libglade \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

BROKEN=		"Uses gdk-pixbuf internals that have disappeared"

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
