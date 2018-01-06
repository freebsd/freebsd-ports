# $FreeBSD$

PORTNAME=	citra
PORTVERSION=	s20180104
PORTREVISION?=	0
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo 3DS emulator/debugger

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSL GPLv2+ LGPL21+ MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/externals/fmt/LICENSE.rst
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_BSL=	${WRKSRC}/externals/catch/LICENSE.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_MIT=	${WRKSRC}/externals/enet/LICENSE
LICENSE_FILE_LGPL21+ =	${_LICENSE_STORE}/LGPL21 # soundtouch

BUILD_DEPENDS=	boost-libs>=1.63:devel/boost-libs
LIB_DEPENDS=	libpng.so:graphics/png

# backend_x64/hostloc.h:93:8: fatal error: no type named 'Reg64' in namespace 'Xbyak'
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	https://github.com/MerryMage/dynarmic/issues/35

USE_GITHUB=	yes
GH_ACCOUNT=	citra-emu
GH_TAGNAME=	a66e4585
GH_TUPLE=	citra-emu:ext-soundtouch:019d208:soundtouch/externals/soundtouch \
		MerryMage:dynarmic:4110494:dynarmic/externals/dynarmic \
		benhoyt:inih:r40:inih/externals/inih/inih \
		catchorg:Catch2:v2.0.1:catch/externals/catch \
		fmtlib:fmt:4.0.0:fmt/externals/fmt \
		herumi:xbyak:v5.53-1-gc5da377:xbyak/externals/xbyak \
		lsalzman:enet:a84c120:enet/externals/enet \
		neobrain:nihstro:7e24743:nihstro/externals/nihstro \
		weidai11:cryptopp:CRYPTOPP_5_6_5-610-g24bc2b8:cryptopp/externals/cryptopp/cryptopp

USES=		cmake:outsource compiler:c++14-lang iconv localbase:ldflags
USE_SDL=	sdl2
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528

OPTIONS_DEFINE=	CURL
OPTIONS_DEFAULT=CURL
OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

CURL_GH_TUPLE=	whoshuu:cpr:1.3.0-12-gb5758fb:cpr/externals/cpr
CURL_LIB_DEPENDS=libcurl.so:ftp/curl
CURL_CMAKE_BOOL=ENABLE_WEB_SERVICE USE_SYSTEM_CURL

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz

QT5_USES=	desktop-file-utils shared-mime-info
QT5_USE=	QT5=qmake_build,buildtools_build,concurrent_build,core,gui,opengl,widgets
QT5_CMAKE_BOOL=	ENABLE_QT
QT5_PLIST_FILES=bin/${PORTNAME}-qt \
		man/man6/${PORTNAME}-qt.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/mime/packages/${PORTNAME}.xml

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		-e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
