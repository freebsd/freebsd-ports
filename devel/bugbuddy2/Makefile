# New ports collection makefile for:	bugbuddy
# Version required:			0.7
# Date created:				23rd February 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	bug-buddy-0.7
PKGNAME=	bugbuddy-0.7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/bug-buddy

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs \
		glade.3:${PORTSDIR}/devel/libglade

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
