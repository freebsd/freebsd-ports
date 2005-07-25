# Ports collection Makefile for:	mlview
# Date created:				24 September 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mlview
PORTVERSION=	0.8
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	barner@FreeBSD.org
COMMENT=	A tree oriented XML editor for Gnome

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF_VER=	259
USE_GNOME=	eel2 gnomehack gnomeprefix gtksourceview
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
USE_REINPLACE=	yes

GCONF_SCHEMAS=	mlview.schemas

.include <bsd.port.pre.mk>

# Autodetect dbus
.if exists (${LOCALBASE}/lib/libdbus-1.so.1)
WITH_DBUS=	yes
.endif

.if defined (WITH_DBUS)
LIB_DEPENDS+=	dbus-1.1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+="--enable-dbus=yes"
.endif

pre-everything::
.if !defined (WITH_DBUS)
	${ECHO_CMD}
	${ECHO_CMD} Re-run with -DWITH_DBUS in order to enable dbus support!
	${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
