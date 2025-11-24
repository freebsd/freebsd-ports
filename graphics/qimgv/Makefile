PORTNAME=	qimgv
PORTVERSION=	1.03.g20250905
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	Fast and easy to use image viewer
WWW=		https://github.com/easymodo/qimgv

LICENSE=	GPLv3

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cmake compiler:c++17-lang desktop-file-utils \
		localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	easymodo
GH_TAGNAME=	6bdfad1f47be2cd5eb54c6da45073f8eee55963f

LDFLAGS+=	-linotify

OPTIONS_DEFINE=		EXIV2 OPENCV VIDEO
OPTIONS_DEFAULT=	EXIV2 OPENCV QT6 VIDEO
OPTIONS_SINGLE=		QT
OPTIONS_SINGLE_QT=	QT5 QT6
OPTIONS_SUB=		yes

OPENCV_DESC=		Enables high quality scaling options
VIDEO_DESC=		Enables video playback via mpv

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CMAKE_BOOL=	EXIV2

OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libopencv_imgproc.so:graphics/opencv
OPENCV_CMAKE_BOOL=	OPENCV_SUPPORT

QT5_USES=		qt:5
QT5_USE=		qt=buildtools:build,linguisttools:build,qmake:build \
			qt=core,gui,printsupport,svg,widgets
QT5_CMAKE_BOOL=		CMAKE_DISABLE_FIND_PACKAGE_Qt6

QT6_USES=		qt:6 gl
QT6_USE=		gl=opengl qt=base,svg,tools:build
QT6_CMAKE_BOOL=		CMAKE_DISABLE_FIND_PACKAGE_Qt5

VIDEO_LIB_DEPENDS=	libmpv.so:multimedia/mpv
VIDEO_CMAKE_BOOL=	VIDEO_SUPPORT

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/qimgv/settings.cpp
	@${REINPLACE_CMD} -e 's|^Exec=|Exec=QT_SCALE_FACTOR_ROUNDING_POLICY=RoundPreferFloor |' \
		${WRKSRC}/qimgv/distrib/qimgv.desktop

.include <bsd.port.mk>
