# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnome-sound-recorder/Makefile 19675 2014-05-19 06:14:07Z gusi $

PORTNAME=	gnome-sound-recorder
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME sound recorder application

LIB_DEPENDS=	libgjs.so:${PORTSDIR}/lang/gjs

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	3
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.gnome-sound-recorder.gschema.xml

.include <bsd.port.mk>
