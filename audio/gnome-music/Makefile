# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-music
PORTVERSION=	3.28.2.1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	itstool:textproc/itstool \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgrilo-0.3.so:net/grilo \
		libtracker-sparql-2.0.so:sysutils/tracker \
		libmediaart-2.0.so:multimedia/libmediaart

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome localbase meson pkgconfig \
		python:3.4+ shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gtk30 introspection pygobject3
USE_GSTREAMER1=	ogg mpg123
INSTALLS_ICONS=	yes
SHEBANG_FILES=	gnome-music.in
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Music.gschema.xml

.include <bsd.port.mk>
