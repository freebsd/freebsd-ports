# Ports collection Makefile for:	mlview
# Date created:				24 September 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mlview
PORTVERSION=	0.6.3
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.6
DIST_SUBDIR=	gnome2

MAINTAINER=	barner@gmx.de
COMMENT=	A tree oriented XML editor for Gnome

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF_VER=	253
USE_GNOME=	gnomeprefix gnomehack eel2
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
