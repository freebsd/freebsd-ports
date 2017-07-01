# $FreeBSD$

PORTNAME=	rpcs3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.2-391
DISTVERSIONSUFFIX=	-g253e7a90
CATEGORIES=	emulators

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PS3 emulator/debugger

LICENSE=	BSD3CLAUSE BSL GPLv2 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/3rdparty/cereal/LICENSE
LICENSE_FILE_BSL=	${WRKSRC}/Utilities/LICENSE_1_0.txt
LICENSE_FILE_MIT=	${WRKSRC}/3rdparty/GSL/LICENSE
LICENSE_FILE_ZLIB=	${WRKSRC}/asmjit/LICENSE.md

LIB_DEPENDS=	libpng.so:graphics/png \
		libavcodec.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires int128 and SSSE3

USE_GITHUB=	yes
GH_ACCOUNT=	RPCS3
GH_TUPLE=	RPCS3:hidapi:hidapi-0.8.0-rc1-23-gc095a22:hidapi/3rdparty/hidapi \
		RPCS3:pugixml:f205aaf:pugixml/3rdparty/pugixml \
		RPCS3:yaml-cpp:release-0.5.3-62-g017626a:yamlcpp/Utilities/yaml-cpp \
		kobalicek:asmjit:1370fe6:asmjit/asmjit \
		Microsoft:GSL:fc5fce4:GSL/3rdparty/GSL \
		USCiLab:cereal:v1.2.0:cereal/3rdparty/cereal

USES=		cmake compiler:c++14-lang iconv:wchar_t localbase:ldflags \
		openal:soft pkgconfig
USE_GL=		gl glew
USE_QT5=	qmake_build buildtools_build core gui widgets
CMAKE_ARGS+=	-DUSE_SYSTEM_LIBPNG=on -DUSE_SYSTEM_FFMPEG=on
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # XXX ports/193528
CXXFLAGS+=	-Wno-macro-redefined # __STDC_*_MACROS sys/cdefs.h vs. llvm-config
LDFLAGS+=	-Wl,--as-needed # GLU
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \

OPTIONS_DEFINE=	GDB LLVM
OPTIONS_DEFAULT=LLVM

GDB_DESC=		GDB remote stub (powerpc64 target)
GDB_CMAKE_BOOL=		WITH_GDB

LLVM_DESC=		LLVM-based PPU recompiler
LLVM_LIB_DEPENDS=	libLLVM-4.0.so:devel/llvm40
LLVM_CMAKE_BOOL_OFF=	WITHOUT_LLVM

post-patch:
	@${REINPLACE_CMD} -e 's/5\.8/5\.7/' ${WRKSRC}/${PORTNAME}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/"unknown"/"${GH_TAGNAME}"/' \
		${WRKSRC}/${PORTNAME}/git-version.cmake

.include <bsd.port.mk>
