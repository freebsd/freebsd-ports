PORTNAME=	sound-juicer
PORTVERSION=	3.38.0
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	9f97ca1faca3.patch:-p1 # https://gitlab.gnome.org/GNOME/sound-juicer/-/merge_requests/27

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean, and lean CD ripper for GNOME
WWW=		http://www.burtonini.com/blog/computers/sound-juicer/

LICENSE=	GPLv3

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5 \
		libdiscid.so:audio/libdiscid \
		libtag.so:audio/taglib \
		libdbus-glib-1.so:devel/dbus-glib \
		libbrasero-media3.so:sysutils/brasero \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome gstreamer meson \
		pkgconfig tar:xz
USE_GSTREAMER=	cdparanoia flac good vorbis
USE_GNOME=	gtk30
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.sound-juicer.gschema.xml

.include <bsd.port.mk>
