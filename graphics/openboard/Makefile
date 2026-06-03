PORTNAME=	openboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.7
CATEGORIES=	graphics education

MAINTAINER=	larone426@gmail.com
COMMENT=	Open source interactive whiteboard application
WWW=		https://www.openboard.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libpoppler.so:graphics/poppler \
		libpoppler-cpp.so:graphics/poppler \
		libquazip1-qt6.so:archivers/quazip@qt6 \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg

USES=		cmake:noninja compiler:c++20-lang desktop-file-utils gl perl5 \
		pkgconfig qt:6 shared-mime-info xorg ssl

USE_GITHUB=	yes
GH_ACCOUNT=	OpenBoard-org
GH_PROJECT=	OpenBoard
USE_GL=		opengl
USE_PERL5=	build
USE_QT=		5compat base declarative multimedia positioning svg tools \
		webchannel webengine
USE_XORG=	x11

CMAKE_ARGS=	-DQT_VERSION=6

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/cmake/DependencyX11.cmake

.include <bsd.port.mk>
