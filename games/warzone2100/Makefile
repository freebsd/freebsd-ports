PORTNAME=	warzone2100
DISTVERSION=	4.6.1
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
LIB_DEPENDS= 	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libminiupnpc.so:net/miniupnpc \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libprotobuf.so:devel/protobuf \
		libsodium.so:security/libsodium \
		libtheoradec.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libzip.so:archivers/libzip
RUN_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

USES=		cmake bison compiler:c++11-lib gl openal:al pkgconfig \
		sdl sqlite tar:xz
USE_GL=		gl
USE_SDL=	sdl2
CMAKE_ON=	WZ_DISABLE_FETCHCONTENT_GIT_CLONE \
		CMAKE_DISABLE_FIND_PACKAGE_Asciidoctor \
		CMAKE_DISABLE_FIND_PACKAGE_Git \
		FETCHCONTENT_FULLY_DISCONNECTED
CMAKE_OFF=	FMT_INSTALL \
		WZ_DOWNLOAD_PREBUILT_PACKAGES \
		WZ_ENABLE_WARNINGS_AS_ERRORS \
		WZ_FORCE_MINIMAL_OPUSFILE
CMAKE_ARGS=	-DWZ_DISTRIBUTOR="FreeBSD ports"

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	VULKAN FRIBIDI DOCS NLS
OPTIONS_DEFAULT=VULKAN FRIBIDI
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_BOOL=	ENABLE_NLS

VULKAN_DESC=		Enable Vulkan backend
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
