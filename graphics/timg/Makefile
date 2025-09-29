PORTNAME=	timg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3
CATEGORIES=	graphics

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Terminal Image and Video Viewer
WWW=		https://github.com/hzeller/timg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libdeflate.so:archivers/libdeflate \
		libexif.so:graphics/libexif \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libpng.so:graphics/png \
		libsixel.so:graphics/libsixel \
		libturbojpeg.so:graphics/libjpeg-turbo

USES=		cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	hzeller

# timg requires libavutil, contained in multimedia/ffmpeg
# isn't splitted libavcodec, libavutil, etc.
CMAKE_ON=	WITH_VIDEO_DECODING WITH_VIDEO_DEVICE
CMAKE_OFF=	TIMG_VERSION_FROM_GIT WITH_OPENSLIDE_SUPPORT WITH_POPPLER \
		WITH_RSVG

PLIST_FILES=	bin/timg \
		share/man/man1/timg.1.gz

.include <bsd.port.mk>
