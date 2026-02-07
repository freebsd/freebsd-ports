PORTNAME=	gstreamer1-plugins-sndio
DISTVERSIONPREFIX=	v
DISTVERSION=	${gst-sndio_VERSION}
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Sndio audio sink and source for GStreamer
WWW=		https://github.com/BSDKaffee/gstreamer1-plugins-sndio/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsndio.so:audio/sndio

USES=		gnome gstreamer pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	BSDKaffee
USE_GNOME=	glib20

PLIST_FILES=	lib/gstreamer-1.0/libgstsndio.so

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
