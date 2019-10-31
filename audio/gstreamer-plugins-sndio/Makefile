# $FreeBSD$

PORTNAME=	gstreamer-plugins-sndio
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.31.1
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Sndio audio sink and source for GStreamer 0.10

LICENSE=	ISCL

LIB_DEPENDS=	libgstaudio-0.10.so:multimedia/gstreamer-plugins \
		libgstbase-0.10.so:multimedia/gstreamer \
		libsndio.so:audio/sndio

USES=		gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	t6
USE_GNOME=	glib20

PLIST_FILES=	lib/gstreamer-0.10/libgstsndio.so

.include <bsd.port.mk>
