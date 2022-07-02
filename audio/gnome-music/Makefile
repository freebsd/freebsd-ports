# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	gnome-music
PORTVERSION=	42.1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		grilo-plugins>0:net/grilo-plugins \
		itstool:textproc/itstool
LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgrilo-0.3.so:net/grilo \
		libhandy-1.so:x11-toolkits/libhandy \
		libmediaart-2.0.so:multimedia/libmediaart \
		libtracker-sparql-3.0.so:sysutils/tracker3
RUN_DEPENDS=	grilo-plugins>0:net/grilo-plugins

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome gstreamer localbase meson pkgconfig \
		python:3.4+ shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gtk40 introspection pygobject3
USE_GSTREAMER=	mpg123 ogg
SHEBANG_FILES=	gnome-music.in
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Music.gschema.xml

.include <bsd.port.mk>
