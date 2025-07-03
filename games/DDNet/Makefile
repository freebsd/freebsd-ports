PORTNAME=	DDNet
PORTVERSION=	19.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	https://ddnet.tw/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	DDraceNetwork, a cooperative racing mod of Teeworlds
WWW=		https://ddnet.tw/ \
		https://github.com/ddnet/ddnet

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cargo cmake compiler:c++17-lang pkgconfig python sqlite:3 ssl tar:xz
CMAKE_ARGS=	-DPYTHON_EXECUTABLE="${PYTHON_CMD}"
CMAKE_OFF=	AUTOUPDATE DOWNLOAD_GTEST PREFER_BUNDLED_LIBS

CXXFLAGS+=	-DBINARY_DIR="\\\"${PREFIX}/bin\\\""

CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=${BUILD_WRKSRC}
CARGO_ENV+=	DDNET_TEST_NO_LINK=1
CARGO_CRATES=	cc-1.0.73 \
		cxx-1.0.71 \
		cxxbridge-flags-1.0.71 \
		cxxbridge-macro-1.0.71 \
		link-cplusplus-1.0.6 \
		proc-macro2-1.0.40 \
		quote-1.0.20 \
		syn-1.0.98 \
		unicode-ident-1.0.1

PORTDATA=	*
DATADIR=	${PREFIX}/share/ddnet

TEST_ENV=	${MAKE_ENV} GTEST_FILTER=-Io.CurrentExe:Jobs.LookupHost:Io.CurrentExe:Jobs.LookupHostWebsocket

OPTIONS_DEFINE=		TEST WEBSOCKET MYSQL VIDEORECORDER UPNP VULKAN
OPTIONS_MULTI=		COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT SERVER VIDEORECORDER UPNP VULKAN
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
TEST_TEST_TARGET=	run_tests  # tests are broken

WEBSOCKET_CMAKE_BOOL=	WEBSOCKETS
WEBSOCKET_LIB_DEPENDS=	libwebsockets.so:net/libwebsockets

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

post-build:
	@${ECHO_MSG} "===> Returning from cargo build to cmake build"
	@${FIND} ${BUILD_WRKSRC} -name libddnet_engine_shared.a -exec ${CP} -p {} ${BUILD_WRKSRC}/release/ \;
	@cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET}

post-patch:
	@${REINPLACE_CMD} -e '/find_package.*Git/ d' ${WRKSRC}/CMakeLists.txt

post-patch-TEST-off:
	@${REINPLACE_CMD} -e '/find_package.*GTest/ d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
