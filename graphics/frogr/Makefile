PORTNAME=	frogr
PORTVERSION=	1.6
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	GNOME

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	1eeb32b94b9e.patch:-p1 # https://gitlab.gnome.org/GNOME/frogr/-/merge_requests/5

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Flickr upload and management tool
WWW=		https://wiki.gnome.org/Apps/Frogr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libexif.so:graphics/libexif \
		libjson-glib-1.0.so:devel/json-glib \
		libgcrypt.so:security/libgcrypt

USES=		compiler:c++11-lang gettext-runtime gettext-tools gnome meson \
		ninja pkgconfig tar:xz
USE_GNOME=	libxml2 glib20 gtk30

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MESON_ARGS=	-Denable-header-bar=true

OPTIONS_DEFINE=		VIDEO
OPTIONS_DEFAULT=	VIDEO

VIDEO_MESON_TRUE=	enable-video
VIDEO_LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1

.include <bsd.port.mk>
