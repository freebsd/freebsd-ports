# New ports collection makefile for:	gnomeiconedit
# Date created:				28th January 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeiconedit
PORTVERSION=	1.0.6
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.abdn.ac.uk/~u07ih/gnome-iconedit/
DISTNAME=	gnome-iconedit-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
