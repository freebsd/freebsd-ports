PORTNAME=	libresprite
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Animated sprite editor and pixel art tool
WWW=		https://libresprite.github.io \
		https://github.com/LibreSprite/LibreSprite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libtinyxml2.so:textproc/tinyxml2 \
		libpng16.so:graphics/png \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++20-lang jpeg libarchive localbase:ldflags pkgconfig sdl xorg
USE_SDL=	image2 sdl2
USE_XORG=	ice pixman sm x11 xcb xcursor xext xi xpm xxf86vm xxf86dga

USE_GITHUB=	yes
GH_ACCOUNT=	LibreSprite
GH_PROJECT=	LibreSprite
GH_TUPLE=	aseprite:simpleini:c94997d:simpleini/third_party/simpleini \
		aseprite:flic:876ef60:flic/src/flic

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/LibreSprite/LibreSprite/issues/672

post-patch: # upstream requires CMake 4.1 which is not available yet
	@${FIND} ${WRKSRC} -name CMakeLists.txt | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's/(cmake_minimum_required\(VERSION )4\.1\)/\13.5)/'

.include <bsd.port.mk>
