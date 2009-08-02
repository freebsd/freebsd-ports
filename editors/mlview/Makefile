# Ports collection Makefile for:	mlview
# Date created:				24 September 2003
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mlview
PORTVERSION=	0.8
PORTREVISION=	9
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tree oriented XML editor for Gnome

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:22
USE_GNOME=	eel2 gnomehack gnomeprefix gtksourceview
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags gnome-vfs-2.0 libgnomeui-2.0`" LIBS="-L${LOCALBASE}/lib `pkg-config --libs gnome-vfs-2.0 libgnomeui-2.0`"

GCONF_SCHEMAS=	mlview.schemas

.include <bsd.port.pre.mk>

# Autodetect dbus
.if exists (${LOCALBASE}/lib/libdbus-1.so.3)
WITH_DBUS=	yes
.endif

.if defined (WITH_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+="--enable-dbus=yes"
.endif

pre-everything::
.if !defined (WITH_DBUS)
	@${ECHO_CMD}
	@${ECHO_CMD} Re-run with -DWITH_DBUS in order to enable dbus support!
	@${ECHO_CMD}
.endif

.include <bsd.port.post.mk>
