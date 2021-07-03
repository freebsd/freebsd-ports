PORTNAME=	devilutionX
DISTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Diablo I engine for modern operating systems

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

_MY_DEPENDS=	CharisSIL>0:x11-fonts/charis
BUILD_DEPENDS=	${_MY_DEPENDS}
LIB_DEPENDS=	libsodium.so:security/libsodium
RUN_DEPENDS=	${_MY_DEPENDS}

USES=		cmake compiler:c++11-lang dos2unix sdl
DOS2UNIX_GLOB=	*.c *.h CMakeLists.txt
USE_GITHUB=	yes
GH_ACCOUNT=	diasurgical
USE_SDL=	mixer2 sdl2 ttf2

CMAKE_ARGS=	-DCMAKE_INSTALL_SHAREDIR:PATH=${PREFIX}/share \
		-DVERSION_NUM=${PORTVERSION}

.if defined(WITH_DEBUG)
CMAKE_ON=	DEBUG
.else
CMAKE_ON=	BINARY_RELEASE
.endif

CXXFLAGS+=	-DTTF_FONT_NAME=\\\"${LOCALBASE}/share/fonts/CharisSIL/CharisSIL-Bold.ttf\\\"

PLIST_FILES=	bin/devilutionx \
		share/applications/devilutionx.desktop \
		share/icons/hicolor/512x512/apps/devilutionx.png \
		share/icons/hicolor/512x512/apps/devilutionx_solid.png

.include <bsd.port.mk>
