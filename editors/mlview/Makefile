# Ports collection Makefile for:	mlview
# Date created:				24 September 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mlview
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.7
DIST_SUBDIR=	gnome2

MAINTAINER=	barner@FreeBSD.org
COMMENT=	A tree oriented XML editor for Gnome

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF_VER=	259
USE_GNOME=	gnomeprefix gnomehack eel2
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
USE_REINPLACE=yes

GCONF_SCHEMAS=	mlview.schemas

post-patch:
	@${REINPLACE_CMD} -e \
		"s,mlview-app-icon.xpm,${PREFIX}/share/gnome/${PORTNAME}/mlview-app-icon.xpm," \
		${WRKSRC}/mlview.desktop.in

.include <bsd.port.mk>
