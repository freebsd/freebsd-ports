PORTNAME=	timg
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Terminal Image and Video Viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	pkgconf>0:devel/pkgconf \
		ffmpeg>0:multimedia/ffmpeg
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libexif.so:graphics/libexif \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libpng.so:graphics/png \
		libturbojpeg.so:graphics/libjpeg-turbo

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	hzeller

# timg requires libavutil, contained in multimedia/ffmpeg
# isn't splitted libavcodec, libavutil, etc.
CMAKE_ON+=	WITH_VIDEO_DECODING WITH_VIDEO_DEVICE
CMAKE_OFF+=	TIMG_VERSION_FROM_GIT WITH_OPENSLIDE_SUPPORT

PLIST_FILES=	bin/timg man/man1/timg.1.gz

.include <bsd.port.mk>
