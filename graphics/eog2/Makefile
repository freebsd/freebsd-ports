# New ports collection makefile for:	eog
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	eog
PORTVERSION=	0.3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/eog

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--without-bonobo
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
