# $FreeBSD$

PORTNAME=	devilutionX
PORTVERSION=	1.0.0
CATEGORIES=	games

MAINTAINER=	benny.goemans@gmail.com
COMMENT=	Diablo I engine for modern operating systems

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	${LOCALBASE}/share/fonts/CharisSIL/CharisSIL-B.ttf:x11-fonts/charis
BUILD_DEPENDS=	${MY_DEPENDS}
LIB_DEPENDS=	libsodium.so:security/libsodium
RUN_DEPENDS=	${MY_DEPENDS}

USES=		cmake compiler:c++11-lang dos2unix sdl
DOS2UNIX_GLOB=	*.c *.h CMakeLists.txt
USE_GITHUB=	yes
GH_ACCOUNT=	diasurgical
USE_SDL=	mixer2 sdl2 ttf2

CMAKE_ARGS=	-DCMAKE_INSTALL_SHAREDIR:PATH=${PREFIX}/share \
		-DGIT_TAG=${PORTVERSION}

.if defined(WITH_DEBUG)
CMAKE_ON=	NIGHTLY_BUILD
.else
CMAKE_ON=	BINARY_RELEASE
.endif

CXXFLAGS+=	-DTTF_FONT_PATH=\\\"${LOCALBASE}/share/fonts/CharisSIL/CharisSIL-B.ttf\\\"

PLIST_FILES=	bin/devilutionx \
		share/applications/devilutionx.desktop \
		share/icons/hicolor/16x16/apps/devilutionx.png \
		share/icons/hicolor/32x32/apps/devilutionx.png \
		share/icons/hicolor/48x48/apps/devilutionx.png

.include <bsd.port.mk>
