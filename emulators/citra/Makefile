# $FreeBSD$

PORTNAME=	citra
PORTVERSION=	s20180528
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

BROKEN_FreeBSD_10=	libc++ does not support C++17 features e.g., weak_from_this

BUILD_DEPENDS=	boost-libs>=1.66:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	citra-emu
GH_TAGNAME=	2772362f
GH_TUPLE=	citra-emu:ext-libressl-portable:cbb1dca:libressl/externals/libressl \
		citra-emu:ext-soundtouch:a6e9119:soundtouch/externals/soundtouch \
		MerryMage:dynarmic:d1d4705:dynarmic/externals/dynarmic \
		benhoyt:inih:r40:inih/externals/inih/inih \
		catchorg:Catch2:v2.1.1:catch/externals/catch \
		fmtlib:fmt:4.0.0-510-g5859e58:fmt/externals/fmt \
		herumi:xbyak:v5.64:xbyak/externals/xbyak \
		lsalzman:enet:39a72ab:enet/externals/enet \
		neobrain:nihstro:fd69de1:nihstro/externals/nihstro \
		weidai11:cryptopp:CRYPTOPP_6_1_0:cryptopp/externals/cryptopp/cryptopp

USES=		cmake:outsource compiler:c++14-lang iconv localbase:ldflags
USE_SDL=	sdl2
EXTRA_PATCHES+=	${EXTRA_PATCHES_${OPSYS}_${OSREL:R}}
EXTRA_PATCHES_FreeBSD_10=	${PATCHDIR}/extra-patch-c++14
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # Qt5Network

OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME} \
		bin/${PORTNAME}-room \
		man/man6/${PORTNAME}.6.gz

QT5_USES=	desktop-file-utils shared-mime-info
QT5_USE=	QT5=qmake_build,buildtools_build,concurrent_build,core,gui,multimedia,opengl,widgets
QT5_CMAKE_BOOL=	ENABLE_QT
QT5_PLIST_FILES=bin/${PORTNAME}-qt \
		"@comment bin/${PORTNAME}-room" \
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
