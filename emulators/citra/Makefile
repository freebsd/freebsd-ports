# $FreeBSD$

PORTNAME=	citra
PORTVERSION=	s20161223
PORTREVISION?=	0
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Nintendo 3DS emulator/debugger

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSL GPLv2+ LGPL21+ UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/externals/dynarmic/externals/fmt/LICENSE.rst
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_BSL=	${WRKSRC}/externals/catch/LICENSE_1_0.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/externals/qhexedit/license.txt
LICENSE_NAME_UNLICENSE=	The Unlicense
LICENSE_TEXT_UNLICENSE=	See http://unlicense.org/
LICENSE_PERMS_UNLICENSE=	${_LICENSE_PERMS_PD}
LICENSE_GROUPS_UNLICENSE=	${_LICENSE_GROUPS_PD}

BUILD_DEPENDS=	boost-libs>=1.57:devel/boost-libs
LIB_DEPENDS=	libpng.so:graphics/png

# backend_x64/hostloc.h:93:8: fatal error: no type named 'Reg64' in namespace 'Xbyak'
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	https://github.com/MerryMage/dynarmic/issues/35

USE_GITHUB=	yes
GH_TUPLE=	citra-emu:${PORTNAME}:51dd13b8 \
		citra-emu:ext-soundtouch:5274ec4:soundtouch/externals/soundtouch \
		MerryMage:dynarmic:3608208:dynarmic/externals/dynarmic \
		fmtlib:fmt:3.0.0-146-g796beaa:fmt/externals/dynarmic/externals/fmt \
		herumi:xbyak:v5.40:xbyak/externals/xbyak \
		neobrain:nihstro:26a0a04:nihstro/externals/nihstro \
		philsquared:Catch:v1.4.0:catch/externals/catch \
		svn2github:inih:603729d:inih/externals/inih/inih

USES=		cmake:outsource compiler:c++14-lang iconv localbase:ldflags
FAVORITE_COMPILER=	${COMPILER_TYPE} # c++14-lib
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # GL

OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

SDL_USE=	SDL=sdl2
SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME} \
		man/man6/${PORTNAME}.6.gz

QT5_USES=	desktop-file-utils shared-mime-info
QT5_USE=	QT5=qmake_build,buildtools_build,core,gui,opengl,widgets
QT5_CMAKE_BOOL=	ENABLE_QT
QT5_PLIST_FILES=bin/${PORTNAME}-qt \
		man/man6/${PORTNAME}-qt.6.gz \
		share/applications/${PORTNAME}.desktop \
		share/mime/packages/${PORTNAME}.xml \
		share/pixmaps/${PORTNAME}.svg

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
