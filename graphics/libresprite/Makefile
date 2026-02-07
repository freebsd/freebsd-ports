PORTNAME=	libresprite
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
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
		libresprite:duktape:6f71555:duktape/third_party/duktape \
		aseprite:flic:876ef60:flic/src/flic \
		aseprite:clip:94693e2:clip/src/clip \
		aseprite:undo:f39b188:undo/src/undo

.include <bsd.port.mk>
