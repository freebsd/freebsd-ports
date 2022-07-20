PORTNAME=	gnome-sound-recorder
DISTVERSION=	42.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME sound recorder application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libgjs.so:lang/gjs \
		libhandy-1.so:x11-toolkits/libhandy

PORTSCOUT=	limitw:1,even

USES=		gettext gnome gstreamer localbase meson pkgconfig python:3.4+ tar:xz
USE_GNOME=	gtk40 intlhack introspection
USE_GSTREAMER=	bad flac ogg pulse
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_CMD}
GLIB_SCHEMAS=	org.gnome.SoundRecorder.gschema.xml

.include <bsd.port.mk>
