# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sound-juicer
PORTVERSION=	3.38.0
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean, and lean CD ripper for GNOME

LICENSE=	GPLv3

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5 \
		libdiscid.so:audio/libdiscid \
		libtag.so:audio/taglib \
		libdbus-glib-1.so:devel/dbus-glib \
		libbrasero-media3.so:sysutils/brasero \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome meson \
		pkgconfig tar:xz
USE_GSTREAMER1=	cdparanoia flac good vorbis
USE_GNOME=	gtk30
INSTALLS_ICONS=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.sound-juicer.gschema.xml

.include <bsd.port.mk>
