# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-music
PORTVERSION=	3.14.3
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:${PORTSDIR}/net/grilo \
		libmediaart-1.0.so:${PORTSDIR}/multimedia/libmediaart

USES=		gettext gmake libtool pathfix pkgconfig \
		python:3 tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	gnomedesktop3 gnomeprefix gtk30 intlhack \
		introspection:build
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	ogg mad
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Music.gschema.xml

PLIST_SUB+=	PYVER=${PYTHON_VER:S/.//}

.include <bsd.port.mk>
