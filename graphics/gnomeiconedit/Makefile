# New ports collection makefile for:	gnomeiconedit
# Version required:			1.0.6
# Date created:				28th January 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gnome-iconedit-1.0.6
PKGNAME=	gnomeiconedit-1.0.6
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.abdn.ac.uk/~u07ih/gnome-iconedit/

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.1:${PORTSDIR}/graphics/gdk-pixbuf

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
