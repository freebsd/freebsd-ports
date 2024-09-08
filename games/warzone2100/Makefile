PORTNAME=	warzone2100
DISTVERSION=	4.5.2
CATEGORIES=	games
MASTER_SITES=	https://github.com/Warzone2100/warzone2100/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}_src
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game
WWW=		https://wz2100.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	7zz:archivers/7-zip \
		a2x:textproc/asciidoc
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libsodium.so:security/libsodium \
		libcurl.so:ftp/curl \
		libminiupnpc.so:net/miniupnpc \
		libopusfile.so:audio/opusfile \
		libopus.so:audio/opus
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		cmake bison compiler:c++11-lib gl openal:al pkgconfig \
		sdl sqlite tar:xz
USE_GL=		gl
USE_SDL=	sdl2
CMAKE_ARGS=	-DWZ_DISTRIBUTOR="FreeBSD ports" \
		-DCMAKE_DISABLE_FIND_PACKAGE_Asciidoctor=TRUE \
	       	-DCMAKE_DISABLE_FIND_PACKAGE_Git=TRUE \
		-DWZ_ENABLE_WARNINGS_AS_ERRORS=FALSE \
		-DFETCHCONTENT_FULLY_DISCONNECTED=TRUE \
		-DWZ_FORCE_MINIMAL_OPUSFILE=FALSE \
		-DWZ_DOWNLOAD_PREBUILT_PACKAGES=FALSE \
		-DFMT_INSTALL=FALSE

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	VULKAN FRIBIDI DOCS NLS
OPTIONS_DEFAULT=VULKAN FRIBIDI
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_BOOL=	ENABLE_NLS

VULKAN_DESC=		Enable Vulkan backend
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
			${LOCALBASE}/bin/glslc:graphics/shaderc
VULKAN_CMAKE_BOOL=	WZ_ENABLE_BACKEND_VULKAN

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Fribidi=TRUE

post-patch:
	@${FIND} ${WRKSRC} -type f -iname "*cmake*" -exec \
		${REINPLACE_CMD} -i '' -e '/find_package(Git/d' {} \;

post-extract:
.for bundled in miniupnp SQLiteCpp/sqlite3
	@${RM} -rf ${WRKSRC}/3rdparty/${bundled}
.endfor
	@${RM} -rf ${WRKSRC}/lib/sound/3rdparty

.include <bsd.port.mk>
