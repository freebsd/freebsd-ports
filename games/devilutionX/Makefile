# $FreeBSD$

PORTNAME=	devilutionX
PORTVERSION=	1.0.0
CATEGORIES=	games

MAINTAINER=	benny.goemans@gmail.com
COMMENT=	Diablo I engine for modern operating systems

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/CharisSIL/CharisSIL-B.ttf:x11-fonts/charis
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake compiler:c++11-lang dos2unix sdl
USE_SDL=	mixer2 sdl2 ttf2
USE_GITHUB=	yes

GH_ACCOUNT=	diasurgical
DOS2UNIX_GLOB=	*.c *.h CMakeLists.txt
INSTALLS_ICONS=	yes

CXXFLAGS+=	-DTTF_FONT_PATH=\\\"${LOCALBASE}/share/fonts/CharisSIL/CharisSIL-B.ttf\\\"
CMAKE_ARGS+=	-D CMAKE_INSTALL_BINDIR:PATH=${BINDIR} \
		-D CMAKE_INSTALL_SHAREDIR:PATH=${PREFIX}/share \
		-D GIT_TAG=${PORTVERSION}

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-D NIGHTLY_BUILD:BOOL=ON
.else
CMAKE_ARGS+=	-D BINARY_RELEASE:BOOL=ON
.endif

PLIST_FILES=	bin/devilutionx \
		share/applications/devilutionx.desktop \
		share/icons/hicolor/16x16/apps/devilutionx.png \
		share/icons/hicolor/32x32/apps/devilutionx.png \
		share/icons/hicolor/48x48/apps/devilutionx.png

.include <bsd.port.mk>
