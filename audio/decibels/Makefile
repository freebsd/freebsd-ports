PORTNAME=	decibels
DISTVERSION=	48.0
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME audio player
WWW=		https://gitlab.gnome.org/GNOME/decibels

DEPRECATED=	Depends on deprecated lang/typescript (which needs a maintainer), see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=289856
EXPIRATION_DATE=2025-11-30

LICENSE=	GPLv3

BUILD_DEPENDS=	tsc:lang/typescript \
		blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libgjs.so:lang/gjs
RUN_DEPENDS=	dbus>0:devel/dbus

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig tar:xz
USE_GNOME=	glib20 gtk40 libadwaita
USE_GSTREAMER=	faad flac lame libav ogg opus ugly vorbis wavpack

PORTSCOUT=	limit:^48\.

.include <bsd.port.mk>
