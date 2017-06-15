# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frogr
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Flickr upload and management tool

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libexif.so:graphics/libexif \
		libjson-glib-1.0.so:devel/json-glib \
		libgcrypt.so:security/libgcrypt

USES=		gmake tar:xz pkgconfig gettext-runtime gettext-tools
USE_GNOME=	libxml2 glib20 gtk30

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-header-bar
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		VIDEO
OPTIONS_DEFAULT=	VIDEO

VIDEO_CONFIGURE_ENABLE=	video
VIDEO_LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1

.include <bsd.port.mk>
