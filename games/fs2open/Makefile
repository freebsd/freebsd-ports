PORTNAME=	fs2open
DISTVERSIONPREFIX=	release_
DISTVERSION=	26_2_0
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source video engine of FreeSpace 2
WWW=		http://scp.indiegames.us

LICENSE=	VOLITION
LICENSE_NAME=	Volition Copyright
LICENSE_FILE=	${WRKSRC}/Copying.md
LICENSE_PERMS=	dist-mirror auto-accept

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lib lua:51 jpeg openal pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	scp-fs2open
GH_PROJECT=	fs2open.github.com
GH_TUPLE=	asarium:libRocket:b0c18e1:libRocket/lib/libRocket
USE_SDL=	sdl3

CMAKE_OFF=	FSO_BUILD_QTFRED FSO_BUILD_WITH_OPENXR
LDFLAGS_i386=	-Wl,-znotext

PLIST_FILES=	bin/fs2_open

OPTIONS_DEFINE=	DISCORD FFMPEG VULKAN
OPTIONS_DEFAULT=	DISCORD FFMPEG VULKAN

DISCORD_DESC=	Discord Rich Presence support
VULKAN_DESC=	Vulkan renderer

DISCORD_CMAKE_BOOL=	FSO_BUILD_WITH_DISCORD
FFMPEG_CMAKE_BOOL=	FSO_BUILD_WITH_FFMPEG
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
VULKAN_CMAKE_BOOL=	FSO_BUILD_WITH_VULKAN
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
			${VULKAN_RUN_DEPENDS}
VULKAN_RUN_DEPENDS=	${LOCALBASE}/lib/libshaderc_shared.so:graphics/shaderc \
			${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/fs2_open \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
