PORTNAME=	mame
DISTVERSION=	0.277
PORTREVISION=	2
CATEGORIES=	emulators games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b4e1f5f1b50fd3402232dd0385cac021ba488db6.patch:-p1 # Only link asmjit if native DRCs are built.

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MAME: a multi-purpose emulation framework
WWW=		https://mamedev.org/

LICENSE=	BSD2CLAUSE BSD3CLAUSE CC0-1.0 GPLv2 LGPL21 MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/docs/legal/BSD-2-Clause
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/docs/legal/BSD-3-Clause
LICENSE_FILE_CC0-1.0=	${WRKSRC}/docs/legal/CC0
LICENSE_FILE_GPLv2=	${WRKSRC}/docs/legal/GPL-2.0
LICENSE_FILE_LGPL21=	${WRKSRC}/docs/legal/LGPL-2.1
LICENSE_FILE_MIT=	${WRKSRC}/docs/legal/MIT
LICENSE_FILE_ZLIB=	${WRKSRC}/docs/legal/Zlib
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	not yet ported to any architecture other than armv7, arm64, x86, and powerpc*

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinxcontrib-svg2pdfconverter>0:textproc/py-sphinxcontrib-svg2pdfconverter@${PY_FLAVOR} \
		asio>0:net/asio \
		genie:devel/genie \
		glm>0:math/glm \
		rapidjson>0:devel/rapidjson
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libFLAC.so:audio/flac \
		libpugixml.so:textproc/pugixml \
		libutf8proc.so:textproc/utf8proc \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang gmake jpeg llvm:min=16 localbase pkgconfig \
		python:build sdl shebangfix sqlite:3 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	mamedev
GH_TAGNAME=	mame${DISTVERSION:S/.//}
USE_SDL=	sdl2
USE_XORG=	x11 xext xi xinerama xrender

MAKEFILE=	makefile
MAKE_ARGS=	SILENT= \
		verbose=yes
MAKE_ENV=	FORCE_DRC_C_BACKEND=1 \
		NO_USE_PORTAUDIO=1 \
		NO_USE_PULSEAUDIO=1 \
		NOWERROR=1 \
		OVERRIDE_AR="llvm-ar${LLVM_VERSION}" \
		OVERRIDE_CC="clang${LLVM_VERSION}" \
		OVERRIDE_CXX="clang++${LLVM_VERSION}" \
		OVERRIDE_LD="lld${LLVM_VERSION}" \
		PRECOMPILE=0 \
		PYTHON_EXECUTABLE="${PYTHON_CMD}" \
		TARGETOS=freebsd \
		USE_PCAP=1 \
		USE_SYSTEM_LIB_ASIO=1 \
		USE_SYSTEM_LIB_EXPAT=1 \
		USE_SYSTEM_LIB_FLAC=1 \
		USE_SYSTEM_LIB_GLM=1 \
		USE_SYSTEM_LIB_JPEG=1 \
		USE_SYSTEM_LIB_PUGIXML=1 \
		USE_SYSTEM_LIB_RAPIDJSON=1 \
		USE_SYSTEM_LIB_SQLITE3=1 \
		USE_SYSTEM_LIB_UTF8PROC=1 \
		USE_SYSTEM_LIB_ZLIB=1 \
		USE_SYSTEM_LIB_ZSTD=1 \
		USE_TAPTUN=1

CFLAGS_aarch64=	-march=armv8-a+crc+crypto

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

SUB_FILES=	mame.ini pkg-message plugin.ini ui.ini

PORTDOCS=	*

OPTIONS_DEFINE=			DOCS
OPTIONS_DEFAULT=		MAME
OPTIONS_GROUP=			EMULATORS EXTRATOOLS HARDWARE
OPTIONS_GROUP_EMULATORS=	MAME MAMENL MAMEVIRTUAL NLS QTDEBUGGER
OPTIONS_GROUP_EXTRATOOLS=	TOOLS
OPTIONS_GROUP_HARDWARE=		OPENMP SSE2
OPTIONS_RADIO=			BUILDTYPE
OPTIONS_RADIO_BUILDTYPE=	DEBUG SIZE_OPTIMIZED_CFLAGS \
				SPEED_OPTIMIZED_CFLAGS
.if !exists(/usr/include/omp.h)
OPTIONS_EXCLUDE=		OPENMP
.endif
OPTIONS_SUB=			yes

BUILDTYPE_DESC=			Application production type
DEBUG_DESC=			Produce profiling data, and symbols for debugging
DOCS_DESC=			Install extensive online MAME documentation
EMULATORS_DESC=			Emulators
EXTRATOOLS_DESC=		Tools
HARDWARE_DESC=			Build with hardware extensions
MAMENL_DESC=			Netlist audio component solver
MAMEVIRTUAL_DESC=		LaserDisk Player
MAME_DESC=			MAME
NLS_DESC=			Install language translations for use in the GUI
QTDEBUGGER_DESC=		Build with Qt interactive low-level machine debugger
SIZE_OPTIMIZED_CFLAGS_DESC=	Optimize for smaller binaries (-Os)
SPEED_OPTIMIZED_CFLAGS_DESC=	Optimize for faster binaries (-O3)
SSE2_DESC=			Build with Streaming SIMD Extensions 2
TOOLS_DESC=			Tools for archiving, development, and multimedia

DEBUG_MAKE_ENV=				DEBUG=1 \
					OPTIMIZE=g \
					STRIP_SYMBOLS=0
DEBUG_MAKE_ENV_OFF=			STRIP_SYMBOLS=1
# Attempt to avoid address space exhaustion during linking, specifically
# on armv7, and possibly other architectures:
DEBUG_LDFLAGS_OFF=			-s
MAMENL_LIB_DEPENDS=			${_EMULATORS_LIB_DEPENDS}
MAMENL_RUN_DEPENDS=			${_EMULATORS_RUN_DEPENDS}
MAMENL_USES=				${_EMULATORS_USES}
MAMENL_USE=				${_EMULATORS_USE}
MAMENL_MAKE_ENV=			${_EMULATORS_MAKE_ENV}
MAMENL_PLIST_SUB=			MAMEDATA=""
MAMENL_PLIST_SUB_OFF=			MAMEDATA="@comment "
MAMEVIRTUAL_LIB_DEPENDS=		${_EMULATORS_LIB_DEPENDS}
MAMEVIRTUAL_RUN_DEPENDS=		${_EMULATORS_RUN_DEPENDS}
MAMEVIRTUAL_USES=			${_EMULATORS_USES}
MAMEVIRTUAL_USE=			${_EMULATORS_USE}
MAMEVIRTUAL_MAKE_ENV=			${_EMULATORS_MAKE_ENV}
MAMEVIRTUAL_PLIST_SUB=			MAMEDATA=""
MAMEVIRTUAL_PLIST_SUB_OFF=		MAMEDATA="@comment "
MAME_LIB_DEPENDS=			${_EMULATORS_LIB_DEPENDS}
MAME_RUN_DEPENDS=			${_EMULATORS_RUN_DEPENDS}
MAME_USES=				${_EMULATORS_USES}
MAME_USE=				${_EMULATORS_USE}
MAME_MAKE_ENV=				${_EMULATORS_MAKE_ENV}
MAME_PLIST_SUB=				MAMEDATA=""
MAME_PLIST_SUB_OFF=			MAMEDATA="@comment "
NLS_USES=				gettext-runtime
OPENMP_MAKE_ENV=			OPENMP=1
OPENMP_MAKE_ENV_OFF=			OPENMP=0
QTDEBUGGER_USES=			qt:6
QTDEBUGGER_USE=				QT=base,tools:build
QTDEBUGGER_MAKE_ENV=			QT_HOME="${PREFIX}" \
					USE_QTDEBUG=1
QTDEBUGGER_MAKE_ENV_OFF=		USE_QTDEBUG=0
SIZE_OPTIMIZED_CFLAGS_MAKE_ENV=		OPTIMIZE=s
SIZE_OPTIMIZED_CFLAGS_CXXFLAGS=		-Os
SPEED_OPTIMIZED_CFLAGS_MAKE_ENV=	OPTIMIZE=3
SPEED_OPTIMIZED_CFLAGS_CXXFLAGS=	-O3
SSE2_MAKE_ENV=				SSE2=1
SSE2_MAKE_ENV_OFF=			SSE2=0
TOOLS_MAKE_ENV=				TOOLS=1
TOOLS_MAKE_ENV_OFF=			TOOLS=0

# man page for command line utility that is not built at all:
_DIST_EXCLUDES=		docs/man/ldplayer.1
# Libraries, and shaders for proprietary platforms:
_DIST_EXCLUDES+=	"bgfx/shaders/dx*" \
			3rdparty/bgfx/examples/runtime/shaders/dx11 \
			3rdparty/bgfx/examples/runtime/shaders/metal \
			3rdparty/dxsdk bgfx/shaders/metal
# Headers that mask system abstractions required to build MAME:
_DIST_EXCLUDES+=	3rdparty/bx/include/compat/freebsd/dirent.h \
			3rdparty/bx/include/compat/freebsd/signal.h
# Make use of Ports instead of bundled libraries:
_DIST_EXCLUDES+=	3rdparty/expat 3rdparty/glm 3rdparty/libflac \
			3rdparty/libjpeg 3rdparty/portmidi 3rdparty/pugixml \
			3rdparty/rapidjson 3rdparty/sqlite3 3rdparty/utf8proc \
			3rdparty/zlib 3rdparty/zstd
# Bundled libraries not used at all:
_DIST_EXCLUDES+=	3rdparty/genie 3rdparty/portaudio 3rdparty/tap-windows6
# pre-built GENie binaries for other platforms:
_DIST_EXCLUDES+=	3rdparty/bx/tools/bin
_DOCS_INSTALL_EXCLUDES=	"-not -name .buildinfo -not -regex ^./_sources.*"
_EMULATORS_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libportmidi.so:audio/portmidi
_EMULATORS_MAKE_ENV=	EMULATOR=1 \
			USE_SYSTEM_LIB_PORTMIDI=1
_EMULATORS_RUN_DEPENDS=	liberation-fonts-ttf>=0:x11-fonts/liberation-fonts-ttf
_EMULATORS_USES=	gl
_EMULATORS_USE=		GL=gl \
			SDL=ttf2
_TOOLS_COMMANDS=	-depth 1 -type f -and -not -type d -and -not -name \
			${PORTNAME}* -perm -o=+x
_TOOLS_MANUALS=		-name *.1 -depth 1 -type f -and -not -type d -and -not \
			-name ${PORTNAME}*

.include <bsd.port.options.mk>

.if ${ARCH:Maarch64} || ${ARCH:Mamd64} || ${ARCH:Mpowerpc64*}
MAKE_ENV+=	PTR64=1
.endif

.if ${ARCH} == aarch64 || ${ARCH} == armv7
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-3rdparty_lzma_C_AesOpt.c
.endif

# Compiling with -pg (PROFILE) causes the linker to run out of memory on i386,
# build with less profiling data:
.if ${ARCH:Mi386}
DEBUG_MAKE_ENV=	PROFILER=1
.else
DEBUG_MAKE_ENV=	PROFILE=1
.endif

.if empty(PORT_OPTIONS:MMAME) && empty(PORT_OPTIONS:MMAMENL) && \
	empty(PORT_OPTIONS:MMAMEVIRTUAL)
MAKE_ENV+=	EMULATOR=0
PLIST_SUB+=	MAMEDATA="@comment "
.endif

post-extract:
	${MV} ${WRKSRC}/src/lib/util/png.h \
		${WRKSRC}/src/lib/util/localpng.h

post-patch:
# Patch build to use bundled PNG.
	${GREP} -rl '"png.h"' ${WRKSRC}/src | \
		${XARGS} ${REINPLACE_CMD} -e 's|"png.h"|"localpng.h"|'
	${REINPLACE_CMD} -e 's|"util/png.h"|"util/localpng.h"|' \
		${WRKSRC}/src/frontend/mame/ui/icorender.cpp
# Patch build to use GENie from Ports:
	${REINPLACE_CMD} -e 's|%%GENIE_PREFIX%%|${PREFIX}/bin/|' \
		${WRKSRC}/makefile \
		${WRKSRC}/3rdparty/bx/makefile

do-build-DOCS-on:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} html SPHINXBUILD=sphinx-build-${PYTHON_VER})

do-build-MAMEVIRTUAL-on:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} SUBTARGET=virtual)

do-build-MAMENL-on:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} SUBTARGET=nl)

post-build:
	(cd ${WRKSRC}/docs && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} man SPHINXBUILD=sphinx-build-${PYTHON_VER})

do-install:
. if ${PORT_OPTIONS:MMAME} || ${PORT_OPTIONS:MMAMENL} || \
	${PORT_OPTIONS:MMAMEVIRTUAL}
.  for DATA in artwork bgfx ctrlr ini hash plugins samples
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${DATA} ${STAGEDIR}${DATADIR})
.  endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
.  for INI in mame plugin ui
	${INSTALL_DATA} ${WRKDIR}/${INI}.ini \
		${STAGEDIR}${ETCDIR}/${INI}.ini.sample
.  endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/keymaps
.  for KEYMAP in be br ch de es fr gb it pt se
	${INSTALL_DATA} ${WRKSRC}/keymaps/km_${KEYMAP}_LINUX.map \
		${STAGEDIR}${DATADIR}/keymaps/km_${KEYMAP}.map
.  endfor
. endif
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/${PORTNAME:tu}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	(cd ${WRKSRC}/docs/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} ${_DOCS_INSTALL_EXCLUDES})

do-install-MAME-on:
	${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.6 \
		${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-MAMENL-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}nl \
		${STAGEDIR}${PREFIX}/bin

do-install-MAMEVIRTUAL-on:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}virtual \
		${STAGEDIR}${PREFIX}/bin

do-install-NLS-on:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} language ${STAGEDIR}${DATADIR} "-not -name *.po")

do-install-TOOLS-on:
	${FIND} ${WRKSRC} ${_TOOLS_COMMANDS} -exec ${INSTALL_PROGRAM} {} \
		${STAGEDIR}${PREFIX}/bin/ \;
	${FIND} ${WRKSRC}/docs/man ${_TOOLS_MANUALS} -exec ${INSTALL_MAN} \
		{} ${STAGEDIR}${PREFIX}/share/man/man1/ \;

.include <bsd.port.mk>
