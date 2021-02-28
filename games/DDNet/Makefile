# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	DDNet
PORTVERSION=	15.3.2
CATEGORIES=	games
MASTER_SITES=	https://ddnet.tw/downloads/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	DDraceNetwork, a cooperative racing mod of Teeworlds

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake compiler:c++11-lang pkgconfig python sqlite:3 ssl tar:xz
CMAKE_ARGS=	-DPYTHON_EXECUTABLE="${PYTHON_CMD}"
CMAKE_OFF=	AUTOUPDATE DOWNLOAD_GTEST PREFER_BUNDLED_LIBS

PORTDATA=	*
DATADIR=	${PREFIX}/share/ddnet

OPTIONS_DEFINE=		CLIENT TEST WEBSOCKETS MYSQL VIDEORECORDER UPNP
OPTIONS_DEFAULT=	CLIENT TEST
OPTIONS_SUB=		yes

CLIENT_DESC=		Build game client
CLIENT_CMAKE_BOOL=	CLIENT
CLIENT_USES=		gettext gl sdl xorg desktop-file-utils
CLIENT_USE=		GL=gl,glew XORG=x11 SDL=sdl2
CLIENT_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libwavpack.so:audio/wavpack \
			libpnglite.so:graphics/pnglite \
			libopusfile.so:audio/opusfile \
			libopus.so:audio/opus \
			libogg.so:audio/libogg \
			libnotify.so:devel/libnotify \
			libcurl.so:ftp/curl

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
