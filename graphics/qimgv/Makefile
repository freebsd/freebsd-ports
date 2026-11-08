PORTNAME=	qimgv
PORTVERSION=	1.03.g20260119
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	kenrap@FreeBSD.org
COMMENT=	Fast and easy to use image viewer
WWW=		https://github.com/easymodo/qimgv

LICENSE=	GPLv3

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		localbase:ldflags qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	easymodo
GH_TAGNAME=	3127a2d211b124ad4fcf853d01e6df9323bdfdc3

USE_GL=		opengl
USE_QT=		base svg tools:build

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5:BOOL=ON

LDFLAGS+=	-linotify

OPTIONS_DEFINE=		EXIV2 OPENCV VIDEO
OPTIONS_DEFAULT=	EXIV2 OPENCV VIDEO
OPTIONS_SUB=		yes

OPENCV_DESC=	Enables high quality scaling options
VIDEO_DESC=	Enables video playback via mpv

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CMAKE_BOOL=	EXIV2

OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libopencv_imgproc.so:graphics/opencv
OPENCV_CMAKE_BOOL=	OPENCV_SUPPORT

VIDEO_LIB_DEPENDS=	libmpv.so:multimedia/mpv
VIDEO_CMAKE_BOOL=	VIDEO_SUPPORT

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/qimgv/settings.cpp

.include <bsd.port.mk>
