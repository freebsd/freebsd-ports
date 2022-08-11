PORTNAME=	DDNet
PORTVERSION=	16.2.2
CATEGORIES=	games
MASTER_SITES=	https://ddnet.tw/downloads/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	DDraceNetwork, a cooperative racing mod of Teeworlds

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libpnglite.so:graphics/pnglite

USES=		cmake compiler:c++17-lang pkgconfig python sqlite:3 ssl tar:xz
CMAKE_ARGS=	-DPYTHON_EXECUTABLE="${PYTHON_CMD}"
CMAKE_OFF=	AUTOUPDATE DOWNLOAD_GTEST PREFER_BUNDLED_LIBS

CXXFLAGS+=	-DBINARY_DIR="\\\"${PREFIX}/bin\\\""

PORTDATA=	*
DATADIR=	${PREFIX}/share/ddnet

TEST_ENV=	${MAKE_ENV} GTEST_FILTER=-Io.CurrentExe:Jobs.LookupHost

OPTIONS_DEFINE=		TEST WEBSOCKETS MYSQL VIDEORECORDER UPNP VULKAN
OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT SERVER TEST VIDEORECORDER UPNP VULKAN
OPTIONS_SUB=		yes

CLIENT_DESC=		Build game client
CLIENT_CMAKE_BOOL=	CLIENT
CLIENT_USES=		gettext gl sdl xorg desktop-file-utils
CLIENT_USE=		GL=gl,glew SDL=sdl2
CLIENT_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libwavpack.so:audio/wavpack \
			libopusfile.so:audio/opusfile \
			libopus.so:audio/opus \
			libogg.so:audio/libogg \
			libnotify.so:devel/libnotify \
			libcurl.so:ftp/curl

SERVER_DESC=		Build game server
SERVER_CMAKE_BOOL=	SERVER
# does not build without these libs, but does not need them in
# runtime either
SERVER_BUILD_DEPENDS=	glew>=0:graphics/glew \
			wavpack>=0:audio/wavpack

TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_TEST_TARGET=	run_tests

WEBSOCKETS_DESC=	Enable WebSocket support for server
WEBSOCKETS_CMAKE_BOOL=	WEBSOCKETS
WEBSOCKETS_LIB_DEPENDS=	libwebsockets.so:net/libwebsockets

MYSQL_DESC=		Enable MySQL/MariaDB support for server
MYSQL_CMAKE_BOOL=	MYSQL
MYSQL_USES=		mysql
MYSQL_LIB_DEPENDS=	libmysqlcppconn.so:databases/mysql-connector-c++

VIDEORECORDER_DESC=	Video recording support using FFmpeg to the client
VIDEORECORDER_CMAKE_BOOL=VIDEORECORDER
VIDEORECORDER_LIB_DEPENDS=libavcodec.so:multimedia/ffmpeg

UPNP_DESC=		UPnP support for the server
UPNP_CMAKE_BOOL=	UPNP
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_IMPLIES=		SERVER

VULKAN_DESC=		Enable the vulkan backend
VULKAN_CMAKE_BOOL=	VULKAN
VULKAN_IMPLIES=		CLIENT
VULKAN_BUILD_DEPENDS=	glslangValidator:graphics/glslang \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

post-extract:
# json-parser and md5 are left intact
.for dep in glew pnglite wavpack zlib
	@${RM} -r ${WRKSRC}/src/engine/external/${dep}
.endfor

post-patch:
	@${REINPLACE_CMD} -e '/find_package.*Git/ d' ${WRKSRC}/CMakeLists.txt

post-patch-TEST-off:
	@${REINPLACE_CMD} -e '/find_package.*GTest/ d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
