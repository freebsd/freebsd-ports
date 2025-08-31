PORTNAME=	devilutionX
DISTVERSION=	1.5.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/diasurgical/devilutionx-assets/releases/download/${DATA_VERSION}/:data
DISTFILES=	devilutionx.mpq?tag=${DATA_VERSION}:data
EXTRACT_ONLY=	${DISTFILES:N*\:data:C/:.*//}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Diablo I engine for modern operating systems
WWW=		https://github.com/diasurgical/DevilutionX

LICENSE=	CC-BY-NC-SA-4.0 OFL11 SUL
LICENSE_COMB=	multi
LICENSE_NAME_SUL=	Sustainable Use License
LICENSE_FILE_SUL=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_SUL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/SimpleIni.h:devel/simpleini
LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		cmake compiler:c++11-lang dos2unix gettext-tools pkgconfig sdl
DOS2UNIX_GLOB=	*.cpp *.h CMakeLists.txt Dependencies.cmake
USE_GITHUB=	yes
GH_ACCOUNT=	diasurgical
GH_PROJECT=	DevilutionX
GH_TUPLE=	diasurgical:libsmackerdec:91e732bb6953489077430572f43fc802bf2c75b2:libsmackerdec/_deps/libsmackerdec-src \
		diasurgical:libmpq:b78d66c6fee6a501cc9b95d8556a129c68841b05:libmpq/_deps/libmpq-src
USE_SDL=	sdl2 image2

CMAKE_ARGS=	-DCMAKE_INSTALL_SHAREDIR:PATH=${PREFIX}/share \
		-DVERSION_NUM="${PORTVERSION}.0"
CMAKE_ON=	DDEVILUTIONX_SYSTEM_LIBFMT \
		FETCHCONTENT_FULLY_DISCONNECTED

DATA_VERSION=	v4
DATADIR=	${PREFIX}/share/diasurgical/devilutionx

OPTIONS_DEFINE=		TEST SOUND LTO DEBUG
OPTIONS_GROUP=		NETWORKING
OPTIONS_GROUP_NETWORKING=	NETWORK TCP ZEROTIER ENCRYPTION
OPTIONS_DEFAULT=	LTO NETWORK TCP ENCRYPTION SOUND

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_BUILD_DEPENDS=	googletest>0:devel/googletest

NETWORK_DESC=		Enable network support
NETWORK_CMAKE_BOOL_OFF=	NONET

TCP_DESC=		TCP multiplayer option
TCP_CMAKE_BOOL_OFF=	DISABLE_TCP
TCP_IMPLIES=		NETWORK
TCP_GH_TUPLE=		diasurgical:asio:4bcf552fcea3e1ae555dde2ab33bc9fa6770da4d:asio/_deps/asio-src

ZEROTIER_DESC=		ZeroTier multiplayer option (broken)
ZEROTIER_BROKEN=	does not build: fatal error: 'sys/appleapiopts.h' file not found
ZEROTIER_CMAKE_BOOL_OFF=DISABLE_ZERO_TIER
ZEROTIER_IMPLIES=	NETWORK
ZEROTIER_GH_TUPLE=	diasurgical:libzt:d6c6a069a5041a3e89594c447ced3f15d77618b8:libzt/_deps/libzt-src \
			diasurgical:ZeroTierOne:b1350ac91118d1bd6bb71c0c41be5f4a30196838:ZeroTierOne/_deps/libzt-src/ext/ZeroTierOne \
			diasurgical:lwip:1bf7e011caf4e992ad139f6cb8c9818a9c1fbe1b:lwip/_deps/libzt-src/ext/lwip \
			diasurgical:lwip-contrib:1f9e26e221a41542563834222c4ec8399be1908f:lwipcontrib/_deps/libzt-src/ext/lwip-contrib

ENCRYPTION_DESC=	Encrypt network packets
ENCRYPTION_CMAKE_BOOL=	PACKET_ENCRYPTION
ENCRYPTION_IMPLIES=	NETWORK
ENCRYPTION_LIB_DEPENDS=	libsodium.so:security/libsodium

SOUND_CMAKE_BOOL_OFF=	NOSOUND
SOUND_LIB_DEPENDS=	libSDL_audiolib.so:audio/sdl_audiolib

LTO_CMAKE_BOOL_OFF=	DISABLE_LTO

DEBUG_CMAKE_BOOL=	DEBUG

post-extract:
	@${MKDIR} ${BUILD_WRKSRC}
	@${LN} -s ${WRKSRC}/_deps ${BUILD_WRKSRC}/_deps

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/Source/init.cpp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/devilutionx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Packaging/nix/devilutionx.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Packaging/nix/devilutionx-hellfire.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/icon.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/devilutionx.png
	${INSTALL_DATA} ${WRKSRC}/Packaging/resources/hellfire.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/devilutionx-hellfire.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/devilutionx.mpq?tag=${DATA_VERSION} ${STAGEDIR}${DATADIR}/devilutionx.mpq

do-test-TEST-on:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/ctest -V

.if make(makesum)
GH_TUPLE+=	${TCP_GH_TUPLE} \
		${ZEROTIER_GH_TUPLE} \
		${SOUND_GH_TUPLE}
.endif

.include <bsd.port.mk>
