# $FreeBSD$

PORTNAME=	gstreamer1-plugins-sndio
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Sndio audio sink and source for GStreamer

LICENSE=	ISCL

LIB_DEPENDS=	libgstaudio-1.0.so:multimedia/gstreamer1-plugins \
		libgstbase-1.0.so:multimedia/gstreamer1 \
		libsndio.so:audio/sndio

USE_GITHUB=	yes
GH_ACCOUNT=	t6

USES=		gettext-runtime pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PLIST_FILES=	lib/gstreamer-1.0/libgstsndio.so

.include <bsd.port.mk>
