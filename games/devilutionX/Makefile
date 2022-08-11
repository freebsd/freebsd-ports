PORTNAME=	devilutionX
DISTVERSION=	1.4.1
CATEGORIES=	games
MASTER_SITES=	https://github.com/diasurgical/devilutionx-assets/releases/download/${DATA_VERSION}/:data
DISTFILES=	devilutionx.mpq?tag=${DATA_VERSION}:data
EXTRACT_ONLY=	${DISTFILES:N*\:data:C/:.*//}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Diablo I engine for modern operating systems

LICENSE=	UNLICENSE CC-BY-NC-SA-4.0 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_UNLICENSE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt
BUILD_DEPENDS=	${LOCALBASE}/include/SimpleIni.h:devel/simpleini

USES=		cmake compiler:c++11-lang dos2unix gettext-tools pkgconfig sdl
DOS2UNIX_GLOB=	*.cpp *.h CMakeLists.txt
USE_GITHUB=	yes
GH_ACCOUNT=	diasurgical
GH_TUPLE=	diasurgical:libsmackerdec:2997ee0e41e91bb723003bc09234be553b190e38:libsmackerdec/_deps/libsmackerdec-src \
		diasurgical:libmpq:0f10bd1600f406b13932bf5351ba713361262184:libmpq/_deps/libmpq-src
USE_SDL=	sdl2 image2

CMAKE_ARGS=	-DCMAKE_INSTALL_SHAREDIR:PATH=${PREFIX}/share \
		-DVERSION_NUM="${PORTVERSION}.0"
CMAKE_ON=	FETCHCONTENT_FULLY_DISCONNECTED

DATA_VERSION=	v2
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
TCP_GH_TUPLE=		diasurgical:asio:ebeff99f539da23d27c2e8d4bdbc1ee011968644:asio/_deps/asio-src

ZEROTIER_DESC=		ZeroTier multiplayer option (broken)
ZEROTIER_BROKEN=	does not build: fatal error: 'sys/appleapiopts.h' file not found
ZEROTIER_CMAKE_BOOL_OFF=DISABLE_ZERO_TIER
ZEROTIER_IMPLIES=	NETWORK
ZEROTIER_GH_TUPLE=	diasurgical:libzt:37a2efb0b925df632299ef07dc78c0af5f6b4756:libzt/_deps/libzt-src \
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
